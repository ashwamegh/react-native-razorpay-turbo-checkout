/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 *
 * @format
 */

import React from 'react';
import type {PropsWithChildren} from 'react';
import {
  SafeAreaView,
  ScrollView,
  StatusBar,
  StyleSheet,
  Text,
  useColorScheme,
  View,
  Button,
} from 'react-native';

import {
  Colors,
  DebugInstructions,
  Header,
  LearnMoreLinks,
  ReloadInstructions,
} from 'react-native/Libraries/NewAppScreen';

import RazorpayCheckout from './RazorpayCheckout';

type SectionProps = PropsWithChildren<{
  title: string;
}>;

function Section({children, title}: SectionProps): JSX.Element {
  const isDarkMode = useColorScheme() === 'dark';

  return (
    <View style={styles.sectionContainer}>
      <Text
        style={[
          styles.sectionTitle,
          {
            color: isDarkMode ? Colors.white : Colors.black,
          },
        ]}>
        {title}
      </Text>
      <Text
        style={[
          styles.sectionDescription,
          {
            color: isDarkMode ? Colors.light : Colors.dark,
          },
        ]}>
        {children}
      </Text>
    </View>
  );
}

function App(): JSX.Element {
  const isDarkMode = useColorScheme() === 'dark';

  const backgroundStyle = {
    backgroundColor: isDarkMode ? Colors.darker : Colors.lighter,
  };

  const onPress = async () => {
    console.log('We will invoke the native module here!');
    // const res = await RazorpayModule.printOrderAndAmount(
    //   'order_skjdksjdbskdjb',
    //   1000.8,
    // );
    // console.log(res);
    const data = {
      key: 'rzp_test_0wFRWIZnH65uny',
      currency: 'INR',
      name: 'eToll by ICICI Bank',
      amount: '1000', // Ensure this is the correct amount in the smallest currency unit
      prefill: {
        email: 'shashank@numadic.com',
        contact: '8587099540',
      },
      theme: {color: '#FF7B05'},
      send_sms_hash: true,
      retry: {enabled: true, max_count: 4},
      disable_redesign_v15: false,
      'experiments.upi_turbo': true,
      ep: 'https://api-web-turbo-upi.ext.dev.razorpay.in/test/checkout.html',
      description: 'Credits towards eToll Addon tag payment',
      image: 'https://etoll-assets.s3.ap-south-1.amazonaws.com/925004492s.jpeg',
    };
    console.log('Calling Razorpay Checkout');

    RazorpayCheckout.open(data)
      .then((data: any) => {
        // handle success
        console.log(`Success: ${data.razorpay_payment_id}`);
      })
      .catch((error: any) => {
        // handle failure
        console.error(`Error: ${error.code} | ${error.description}`);
      });
  };

  return (
    <SafeAreaView style={backgroundStyle}>
      <StatusBar
        barStyle={isDarkMode ? 'light-content' : 'dark-content'}
        backgroundColor={backgroundStyle.backgroundColor}
      />
      <ScrollView
        contentInsetAdjustmentBehavior="automatic"
        style={backgroundStyle}>
        <Header />

        <Button title="Pay with Razorpay" color="#0CA72F" onPress={onPress} />
        <View
          style={{
            backgroundColor: isDarkMode ? Colors.black : Colors.white,
          }}>
          <Section title="Step One">
            Edit <Text style={styles.highlight}>App.tsx</Text> to change this
            screen and then come back to see your edits.
          </Section>
          <Section title="See Your Changes">
            <ReloadInstructions />
          </Section>
          <Section title="Debug">
            <DebugInstructions />
          </Section>
          <Section title="Learn More">
            Read the docs to discover what to do next:
          </Section>
          <LearnMoreLinks />
        </View>
      </ScrollView>
    </SafeAreaView>
  );
}

const styles = StyleSheet.create({
  sectionContainer: {
    marginTop: 32,
    paddingHorizontal: 24,
  },
  sectionTitle: {
    fontSize: 24,
    fontWeight: '600',
  },
  sectionDescription: {
    marginTop: 8,
    fontSize: 18,
    fontWeight: '400',
  },
  highlight: {
    fontWeight: '700',
  },
});

export default App;
