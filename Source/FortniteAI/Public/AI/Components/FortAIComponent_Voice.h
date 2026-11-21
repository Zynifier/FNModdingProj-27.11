// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FortAIComponent_Voice.generated.h"

class UFortTaggedSoundBank;

UCLASS(BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class UFortAIComponent_Voice : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta=(BlueprintGetter))
	UFortTaggedSoundBank* GetVoiceSoundBank() const;

	UFUNCTION(BlueprintCallable, meta=(BlueprintSetter))
	void SetVoiceSoundBank(UFortTaggedSoundBank* InSoundBank);

protected:
	UPROPERTY(EditAnywhere, BlueprintGetter=GetVoiceSoundBank, BlueprintSetter=SetVoiceSoundBank, Replicated, Category="FortAIComponent_Voice")
	TObjectPtr<UFortTaggedSoundBank> VoiceSoundBank;

};

