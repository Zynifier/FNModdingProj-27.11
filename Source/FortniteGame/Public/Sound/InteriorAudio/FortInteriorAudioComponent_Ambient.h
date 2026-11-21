// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Sound/InteriorAudio/FortInteriorAudioComponent.h"
#include "FortInteriorAudioComponent_Ambient.generated.h"

class UAmbientAudioDataAsset;
class USoundMix;

UENUM(BlueprintType)
enum class EInteriorAudioAmbientState : uint8
{
	Indoors = 0,
	Outdoors = 1,
	PartialOutdoors = 2,
	Max_None = 3 UMETA(DisplayName="None"),
};

UENUM(BlueprintType)
namespace EInteriorAudioRoomSize
{
	enum Type
	{
		Small = 0,
		Medium = 1,
		Large = 2,
		Max_None = 3 UMETA(DisplayName="None"),
	};
}

USTRUCT(BlueprintType)
struct FInteriorAudioAmbientInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="InteriorAudioAmbientInfo")
	EInteriorAudioAmbientState CurrentState;

	UPROPERTY(BlueprintReadOnly, Category="InteriorAudioAmbientInfo")
	FGameplayTag CurrentRoomSizeTag;

	UPROPERTY()
	TObjectPtr<UAmbientAudioDataAsset> CurrentAmbientBank;

	UPROPERTY()
	TObjectPtr<UAmbientAudioDataAsset> PreviousAmbientBank;

};

USTRUCT(BlueprintType)
struct FInteriorAudioRoomSizeInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="InteriorAudioRoomSizeInfo")
	float SizeRequired;

	UPROPERTY(EditDefaultsOnly, Category="InteriorAudioRoomSizeInfo")
	FGameplayTag SizeTag;

};

UCLASS(BlueprintType, Blueprintable)
class UFortInteriorAudioComponent_Ambient : public UFortInteriorAudioComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Detection Properties | Building Counts")
	int32 TotalBuildingCountRequiredForInterior;

	UPROPERTY(EditDefaultsOnly, Category="Detection Properties | Building Counts")
	int32 TotalBuildingCountRequiredForPartialExterior;

	UPROPERTY(EditDefaultsOnly, Category="Audio | SoundMix")
	TObjectPtr<USoundMix> InteriorSoundMix;

	UPROPERTY(EditDefaultsOnly, Category="Audio | SoundMix")
	TObjectPtr<USoundMix> PartialInteriorSoundMix;

	UPROPERTY(EditDefaultsOnly, Category="Audio | SoundMix")
	TObjectPtr<USoundMix> PartialExteriorSoundMix;

	UPROPERTY(EditDefaultsOnly, Category="Audio | SoundMix")
	int32 AmbientEntryPriority;

	UPROPERTY(EditDefaultsOnly, Category="Audio | Ambient System", meta=(ArraySizeEnum="/Script/FortniteGame.EFortResourceType"))
	TObjectPtr<UAmbientAudioDataAsset> AmbientBanks[6];

	UPROPERTY(EditDefaultsOnly, Category="Audio | Ambient System")
	float AmbientBankFadeInTime;

	UPROPERTY(EditDefaultsOnly, Category="Audio | Ambient System")
	float AmbientBankFadeOutTime;

	UPROPERTY(EditDefaultsOnly, Category="Audio | Ambient System")
	FGameplayTag AmbientTagOutdoors;

	UPROPERTY(EditDefaultsOnly, Category="Audio | Ambient System")
	FGameplayTag AmbientTagIndoors;

	UPROPERTY(EditDefaultsOnly, Category="Audio | Ambient System")
	FGameplayTag AmbientTagIndoorPlayerBuilt;

	UPROPERTY(EditDefaultsOnly, Category="Audio | Ambient System", meta=(TitleProperty="SizeRequired"))
	TArray<FInteriorAudioRoomSizeInfo> RoomSizeInfo;

	UPROPERTY(BlueprintReadOnly, Category="Data")
	FInteriorAudioAmbientInfo AmbientInfo;

};

