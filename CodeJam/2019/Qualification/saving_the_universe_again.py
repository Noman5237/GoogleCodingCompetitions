# created By: Anonyman637
# created On: 2019-09-01 07:45:38


def get_program_stat(program):
    """
    Getting detailed information about robot aliens program
    @return c           possible hacking position and no of moves required
    @return no_of_s     How many times robot alien is going to shoot
    
    """

    modRevProgram = program[::-1]
    no_of_s = 0
    c = []
    for instruction in modRevProgram:
        if instruction == "S":
            no_of_s += 1
        else:
            c.append(no_of_s)
    return c[::-1], no_of_s


def get_damage_stat(program):
    """
    Reads the program and calculates the amount of damage
    the robot alien can do to the universe

    """
    total_damage = 0
    damage = 1
    for instruction in program:
        if instruction == "S":
            total_damage += damage
        else:
            damage *= 2

    return total_damage


def get_minimized_damage(moves):
    """
    Calculates the amount of damaged that is reduced after specified hacking moves

    """
    damage_minimized = 0
    for mi in range(len(moves)):
        damage_minimized += 2 ** mi * moves[mi]

    return damage_minimized


no_of_tests = int(input())
for t in range(1, no_of_tests + 1):
    D, P = input().split()
    D = int(D)

    C, nS = get_program_stat(P)

    if nS > D:
        print("Case #{0}: IMPOSSIBLE".format(t))
        continue
    elif len(C) == 0:
        print("Case #{0}: 0".format(t))
        continue

    total_damage_count = get_damage_stat(P)

    i = len(C) - 1
    c_fill = [0] * len(C)
    while i >= 0:
        if total_damage_count - get_minimized_damage(c_fill) <= D:
            print("Case #{0}: {1}".format(t, sum(c_fill)))
            break
        if c_fill[i] < C[i]:
            c_fill[i] += 1
        else:
            i -= 1
    else:
        # Program with no S will not get their damage minimized
        # And will just exit quietly
        print("Case #{0}: {1}".format(t, sum(c_fill)))
