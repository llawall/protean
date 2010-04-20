﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace protean
{
    namespace clr
    {
        namespace test
        {
            using NUnit.Framework;
            using protean.clr;

            [TestFixture]
            public class TestXMLStreams
            {
                [Test]
                public void TestDictionary()
                {
                    Variant input = new Variant(Variant.EnumType.Dictionary);
                    input.Add("key1", new Variant("value1"));
                    input.Add("key2", new Variant("value2"));

                    StringBuilder ibuffer = new StringBuilder();
                    System.IO.StringWriter istream = new System.IO.StringWriter(ibuffer);
                    XMLWriter writer = new XMLWriter(istream);
                    writer.Write(input);

                    System.IO.StringReader ostream = new System.IO.StringReader(ibuffer.ToString());
                    XMLReader reader = new XMLReader(ostream);
                    Variant output = reader.Read();

                    Assert.True(input.Equals(output));
                }
            }
        }
    }
}