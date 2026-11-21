// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortSoundSequence.generated.h"

class USoundBase;

USTRUCT(BlueprintType)
struct FSoundSequenceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SoundSequenceData")
	TObjectPtr<USoundBase> Sound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SoundSequenceData")
	float Delay;

};

UCLASS(BlueprintType)
class UFortSoundSequence : public UDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	void GetSoundSequenceData(TArray<FSoundSequenceData>& OutSoundSequenceData);

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	bool GetSoundSequenceDataForIndex(const int32 Index, FSoundSequenceData& OutSoundSequenceData) const;

private:
	UPROPERTY(EditAnywhere, Category="FortSoundSequence")
	TArray<FSoundSequenceData> SoundSequenceData;

};

