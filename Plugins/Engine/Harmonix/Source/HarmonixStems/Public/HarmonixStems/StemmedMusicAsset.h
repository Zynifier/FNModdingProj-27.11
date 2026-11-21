// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/Interface_AsyncCompilation.h"
#include "UObject/NoExportTypes.h"
#include "StemmedMusicAsset.generated.h"

class UMediaPlayer;
class UMidiFile;
class USoundWave;
class UStemConfiguration;

USTRUCT(BlueprintType)
struct HARMONIXSTEMS_API FMusicAssetStemChannel
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HarmonixStems")
	int32 SourceIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HarmonixStems")
	float LevelInDecibels;

};

USTRUCT(BlueprintType)
struct HARMONIXSTEMS_API FMediaStreamAssetStem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HarmonixStems")
	FName StemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HarmonixStems")
	TArray<FMusicAssetStemChannel> Channels;

};

USTRUCT(BlueprintType)
struct HARMONIXSTEMS_API FWavesAssetStem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HarmonixStems")
	FName StemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HarmonixStems")
	TObjectPtr<USoundWave> SoundWave;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, EditFixedSize, Category="HarmonixStems", meta=(DisplayName="Channel Levels (dB)"))
	TArray<float> ChannelLevelsInDecibels;

};

UCLASS(Abstract, BlueprintType, ClassGroup=("Harmonix"))
class HARMONIXSTEMS_API UStemmedMusicAsset : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HarmonixStems")
	TObjectPtr<UMidiFile> MidiFile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HarmonixStems")
	TObjectPtr<UStemConfiguration> StemConfiguration;

};

UCLASS(BlueprintType, ClassGroup=("Harmonix"))
class HARMONIXSTEMS_API UStemmedMediaStreamAsset : public UStemmedMusicAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HarmonixStems")
	TObjectPtr<UMediaPlayer> MediaPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HarmonixStems")
	TArray<FMediaStreamAssetStem> StreamStems;

};

UCLASS(BlueprintType, ClassGroup=("Harmonix"))
class HARMONIXSTEMS_API UStemmedWavesAsset : public UStemmedMusicAsset, public IInterface_AsyncCompilation
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HarmonixStems")
	TArray<FWavesAssetStem> WavesStems;

	virtual bool IsCompiling() const override;

};

