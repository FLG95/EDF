<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>
    <header>
        <h1>Welcome to The README of Cy EDF Project 😊</h1>
    </header>
    <main>
        <section>
            <h2>Cy EDF</h2>
            <p>Pre-Ing-2 S1 project</p>
        </section>
        <section>
            <h2>Projects</h2>
            <p>Cy EDF Pre-Ing-2 S1 project</p>
            <p>Subject: <strong>CyWire subject.pdf</strong></p>
            <h3>Arguments:</h3>
            <ul>
                <li><strong>input_file:</strong> path to the input file</li>
                <li><strong>station_type:</strong> type of station (hvb, hva, lv)</li>
                <li><strong>consumer_type:</strong> type of consumer (indiv, comp, all)</li>
                <li><strong>OPTIONAL:</strong> power_plant_id: id of the power plant</li>
            </ul>
            <p> Not all cases are allowed (hvb supports all/indiv; hva supports all/indiv).</p>
            <h3>Exemple d'utilisation :</h3>
            <p>./main.sh Input/[input_file] [station_type(hvb, hva, lv)] [consumer_type(indiv, comp, all)] exemple:</p>
            <pre>
./main.sh Input/c-wire_v25.dat hva comp
            </pre>
        </section>
    </main>
</body>
</html>
