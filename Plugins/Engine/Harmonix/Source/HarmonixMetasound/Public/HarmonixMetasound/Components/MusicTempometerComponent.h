// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HarmonixMidi/BarMap.h"
#include "HarmonixMidi/MidiSongPos.h"
#include "MusicTempometerComponent.generated.h"

class AActor;
class UMaterialParameterCollection;
class UMaterialParameterCollectionInstance;
class UMusicClockComponent;

/**
 * UMusicTempometerComponent provides playback properties of a UMusicClockComponent on its actor and optionally updates a UMaterialParameterCollection.
 */
UCLASS(PrioritizeCategories=("MusicClock"), ClassGroup=("MetaSoundMusic"), meta=(BlueprintSpawnableComponent, DisplayName="Music Tempometer", ScriptName="MusicTempometerComponent"))
class HARMONIXMETASOUND_API UMusicTempometerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	/**
	 * Progress of the current bar [0, 1).
	 */
	UFUNCTION(BlueprintPure, Category="MusicClock")
	float GetBarProgress() const;

	/**
	* Bars from the beginning of the music. Includes all
	* count-in and pickup bars (ie. won't be negative when the music starts,
	* and bar 1 beat 1 of the music may not be equal to elapsed bar 0.0!
	*/
	UFUNCTION(BlueprintPure, Category="MusicClock")
	float GetBarsIncludingCountIn() const;

	/**
	 * Progress of the current beat [0, 1).
	 */
	UFUNCTION(BlueprintPure, Category="MusicClock")
	float GetBeatProgress() const;

	/**
	 * Beats from the beginning of the music. Includes all
	 * count-in and pickup bars/beats (ie. won't be negative when the music starts,
	 * and elapsed beat 0.0 may not equal a timestamp of bar 1 beat 1!
	 */
	UFUNCTION(BlueprintPure, Category="MusicClock")
	float GetBeatsIncludingCountIn() const;

	UFUNCTION(BlueprintPure, Category="MusicClock", meta=(BlueprintGetter))
	const UMusicClockComponent* GetClock() const;

	UFUNCTION(BlueprintPure, Category="MusicClock")
	UMaterialParameterCollection* GetMaterialParameterCollection() const;

	/**
	 * Seconds from Bar 1 Beat 1 of the music. If the music has a count-in
	 * or pickup bars this number may be negative when the music starts!
	 */
	UFUNCTION(BlueprintPure, Category="MusicClock")
	float GetSecondsFromBarOne() const;

	/**
	* Seconds from the beginning of the entire music authoring.
	* Includes all count-in and pickup bars (ie. won't be negative when
	* the music starts, and bar 1 beat 1 may not be at 0.0 seconds!
	*/
	UFUNCTION(BlueprintPure, Category="MusicClock")
	float GetSecondsIncludingCountIn() const;

	/**
	 * The FSongPos for which the game thread is currently issuing graphics rendering commands, according to calibration data.
	 */
	UFUNCTION(BlueprintPure, Category="MusicClock")
	const FMidiSongPos& GetSongPos() const;

	/**
	 * Current tempo (beats per minute).
	 */
	UFUNCTION(BlueprintPure, Category="MusicClock")
	float GetTempo() const;

	/**
	 * Current time signature denominator (scale from note duration to beat fraction for a simple meter).
	 */
	UFUNCTION(BlueprintPure, Category="MusicClock")
	float GetTimeSignatureDenominator() const;

	/**
	 * Current time signature numerator (beats per bar for a simple meter).
	 */
	UFUNCTION(BlueprintPure, Category="MusicClock")
	float GetTimeSignatureNumerator() const;

	/**
	 * Current bar & beat in the traditional format, where...
	 *     - bar 1 beat 1 is the beginning of the song.
	 *     - bars BEFORE bar 1 are count-in or "pickup" bars.
	 *     - beat is always 1 or greater.
	 */
	UFUNCTION(BlueprintPure, Category="MusicClock")
	FMusicTimestamp GetTimestamp() const;

	/**
	 * SetSongPosInterface allows setting any UObject implementing the ISongPosInterface as the attribute source.
	 */
	UFUNCTION(BlueprintCallable, Category="MusicClock")
	void SetClock(UMusicClockComponent* InClockComponent);

	/**
	 * SetSongPosInterfaceFromActor sets the actor or the first of its owned components that implements ISongPosInterface as the attribute source.
	 * BeginPlay calls this on the owning actor when the source ISongPosInterface is not set.
	 */
	UFUNCTION(BlueprintCallable, Category="MusicClock")
	void SetClockFromActor(AActor* Actor);

	/**
	 * Set the MaterialParameterCollection whose parameters will be updated.
	 * If any of the named parameters are missing they will be ignored.
	 */
	UFUNCTION(BlueprintCallable, Category="MusicClock", meta=(BlueprintSetter))
	void SetMaterialParameterCollection(UMaterialParameterCollection* InMaterialParameterCollection);

	/**
	 * Seconds from the beginning of the entire music authoring.
	 * Includes all count-in and pickup bars (ie. won't be negative when 
	 * the music starts, and bar 1 beat 1 may not be at 0.0 seconds!
	 */
	UPROPERTY(EditAnywhere, Category="MusicClock")
	FName SecondsIncludingCountInParameterName;

	/**
	 * Bars from the beginning of the music. Includes all 
	 * count-in and pickup bars (ie. won't be negative when the music starts,
	 * and bar 1 beat 1 of the music may not be equal to elapsed bar 0.0!
	 * NOTE: This Bar, unlike the Bar in the MusicTimestamp structure, is
	 * floating point and will include a fractional portion.
	 */
	UPROPERTY(EditAnywhere, Category="MusicClock")
	FName BarsIncludingCountInParameterName;

	/**
	 * Total Beats from the beginning of the music. Includes all 
	 * count-in and pickup bars/beats (ie. won't be negative when the music starts,
	 * and elapsed beat 0.0 may not equal a timestamp of bar 1 beat 1!
	 */
	UPROPERTY(EditAnywhere, Category="MusicClock")
	FName BeatsIncludingCountInParameterName;

	/**
	 * Seconds from Bar 1 Beat 1 of the music. If the music has a count-in
	 * or pickup bars this number may be negative when the music starts!
	 */
	UPROPERTY(EditAnywhere, Category="MusicClock")
	FName SecondsFromBarOneParameterName;

	/**
	 * This is the bar member of the MusicTimestamp structure which represents a classic
	 * "music time" where bar 1 beat 1 is the beginning of the music AFTER count-in and pickups.
	 * If the music has a count-in or pickup bars this number may be negative (or zero) until 
	 * bar 1 beat 1 is reached!
	 * NOTE: Unlike "BarsFromCountIn", Bar here will be an integer! This because it is the bar 
	 * from the MusicTimestamp structure which also provides a "beat in bar" member to denote 
	 * a "distance into the bar".
	 */
	UPROPERTY(EditAnywhere, Category="MusicClock")
	FName TimestampBarParameterName;

	/**
	 * This is the beat member of the MusicTimestamp structure which represents a classic
	 * "music time" where bar 1 beat 1 is the beginning of the music AFTER count-in and pickups.
	 * If the music has a count-in or pickup bars this number may be negative (or zero) until
	 * bar 1 beat 1 is reached! NOTE: beat in this context is 1 based! The first beat in a bar
	 * is beat 1!
	 * Note: This is a floating point number.
	 */
	UPROPERTY(EditAnywhere, Category="MusicClock")
	FName TimestampBeatInBarParameterName;

	/**
	 * Progress of the current bar [0, 1]. This is the same as the
	 * fractional part of BarsFromCountIn.
	 */
	UPROPERTY(EditAnywhere, Category="MusicClock")
	FName BarProgressParameterName;

	/**
	 * Progress of the current beat [0, 1]. This is the same as the
	 * fractional part of BeatsFromCountIn;
	 */
	UPROPERTY(EditAnywhere, Category="MusicClock")
	FName BeatProgressParameterName;

	/**
	 * Current time signature numerator (beats per bar).
	 */
	UPROPERTY(EditAnywhere, Category="MusicClock")
	FName TimeSignatureNumeratorParameterName;

	/**
	 * Current time signature denominator (scale from note duration to beat).
	 */
	UPROPERTY(EditAnywhere, Category="MusicClock")
	FName TimeSignatureDenominatorParameterName;

	/**
	 * Current tempo (beats per minute).
	 */
	UPROPERTY(EditAnywhere, Category="MusicClock")
	FName TempoParameterName;

private:
	UFUNCTION(BlueprintPure, Category="MusicClock")
	const UMusicClockComponent* GetClockNoMutex() const;

	UPROPERTY(BlueprintGetter=GetSongPos, Transient, Category="MusicClock", meta=(AllowPrivateAccess="true"))
	FMidiSongPos SongPos;

	/**
	 * Music whose tempo to detect.
	 */
	UPROPERTY(BlueprintGetter=GetClock, BlueprintSetter=SetClock, Export, Category="MusicClock", meta=(EditInline="true", AllowPrivateAccess="true"))
	TObjectPtr<UMusicClockComponent> MusicClock;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetMaterialParameterCollection, BlueprintSetter=SetMaterialParameterCollection, Category="MusicClock", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UMaterialParameterCollection> MaterialParameterCollection;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialParameterCollectionInstance> MaterialParameterCollectionInstance;

};

