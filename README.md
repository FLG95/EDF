<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Cy EDF Project</title>
</head>
<body>
    <header>
        <h1>Welcome to The README of Cy EDF project 😊</h1>
    </header>
    
    <main>
        <section>
            <h2>Project Overview</h2>
            <p>
                Cy EDF<br>
                Pre-Ing-2 S1 project<br>
                Subject: CyWire subject.pdf
            </p>
        </section>

        <section>
            <h2>Arguments</h2>
            <p>
                <strong>input_file:</strong> path to the input file<br>
                <strong>station_type:</strong> type of station (hvb, hva, lv)<br>
                <strong>consumer_type:</strong> type of consumer (indiv, comp, all)<br>
                <strong>OPTIONAL:</strong> power_plant_id: id of the power plant<br><br>
                <em>Note:</em> Not all cases are allowed (e.g., hvb all/indiv and hva all/indiv).<br><br>
                Example usage:<br>
                <code>./main.sh Input/[input_file] [station_type(hvb, hva, lv)] [consumer_type(indiv, comp, all)]</code><br>
                Example:<br>
                <code>./main.sh Input/c-wire_v25.dat hva comp</code>
            </p>
        </section>
    </main>

    <footer>
        <p>&copy; 2024 My Website</p>
        <p>Contributors: Goupil Florian, Morille Paul, Wingering Cyprien</p>
    </footer>
</body>
</html>
