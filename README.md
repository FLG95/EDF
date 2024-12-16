<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>
    <header>
        <h1 align="center">Welcome to The README of Cy EDF Project 😊</h1>
    </header>
    <main>
        <section>
            <h2>⚡Cy EDF⚡</h2>
            <p>Pre-Ing-2 S1 project</p>
        </section>
        <section>
            <h2>Projects</h2>
            <p>Cy EDF Pre-Ing-2 S1 project</p>
            <p>Subject : <a href="C-Wire.pdf" target="_blank"><strong>C-Wire.pdf</strong></a></p>
            <h3>Arguments :</h3>
            <ul>
                <li><strong>Input_file :</strong> path to the input file</li>
                <li><strong>Station_type :</strong> type of station (hvb, hva, lv)</li>
                <li><strong>Consumer_type :</strong> type of consumer (indiv, comp, all)</li>
                <li><strong>OPTIONAL :</strong> power_plant_id: id of the power plant</li>
            </ul>
            <p> Not all cases are allowed (hvb supports all/indiv; hva supports all/indiv).</p>
            <h3>Example of use :</h3>
            <p>./main.sh Input/[input_file] [station_type(hvb, hva, lv)] [consumer_type(indiv, comp, all)]  (power_plant_id) Exemple:</p>
            <pre>
./main.sh Input/c-wire_v25.dat hva comp
            </pre>
            <h3>Shell exit code :</h3>
            <p> *à remplir*</p>
            <h3>C exit code :</h3>
             <ul>
                <li>0 : Succes</li>
                <li>10 : Error by passing arguments</li>
                <li>20 : Invalid arguments</li>
                <li>30 : Error when reading file</li>
                <li>40 : Error when building AVL tree</li>
                <li>50 : Error when writing output file</li>
                <li>60 : Error when using AVL tree</li>
            </ul>
        </section>
    <section>
        <hr>
<h3>Contributors</h3>
         <p> Goupil Florian-MI03 22402529</p>
         <p> Morille Paul-MI03 22402306</p>
         <p> Wingering Cyprien-MI03 22401105</p>
    </section>
    </main>
</body>
</html>
