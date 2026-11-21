// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent_VoiceBase.h"
#include "FortAthenaAISpawnerDataComponent_Voice.generated.h"

class UFortAIComponent_Voice;
class UFortTaggedSoundBank;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAISpawnerDataComponent_Voice : public UFortAthenaAISpawnerDataComponent_VoiceBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Voice", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAIComponent_Voice> VoiceComponentClass;

	UPROPERTY(EditAnywhere, Category="Voice", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UFortTaggedSoundBank> SoundBank;

	UPROPERTY(EditAnywhere, Category="Voice", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UFortTaggedSoundBank> MaleSoundBankOverride;

	UPROPERTY(EditAnywhere, Category="Voice", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UFortTaggedSoundBank> FemaleSoundBankOverride;

};

