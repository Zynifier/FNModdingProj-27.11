// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "GameplayTagContainer.h"
#include "FortAnimNotifyState_EmoteSound.generated.h"

class UAudioComponent;
class USoundBase;

UCLASS(MinimalAPI, HideCategories=("Object"))
class UFortAnimNotifyState_EmoteSound : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Sound")
	TObjectPtr<USoundBase> EmoteSound1P;

	UPROPERTY(EditAnywhere, Category="Sound")
	TObjectPtr<USoundBase> EmoteSound3P;

	UPROPERTY(EditAnywhere, Category="Sound", meta=(Categories="MusicEventSubsystem.Event"))
	FGameplayTag MusicEventTagOverride1P;

	UPROPERTY(EditAnywhere, Category="Sound", meta=(Categories="MusicEventSubsystem.Event"))
	FGameplayTag MusicEventTagOverride3P;

	UPROPERTY(EditAnywhere, Category="Sound")
	bool bPrimarySound;

	UPROPERTY(EditAnywhere, Category="Sound", meta=(EditCondition="!bPrimarySound"))
	FName SoundName;

	UPROPERTY(EditAnywhere, Category="Sound")
	float FadeOutTime;

	UPROPERTY(EditAnywhere, Category="Sound")
	bool bEmoteLeaderOnly;

	UPROPERTY(EditAnywhere, Category="Sound")
	bool bStopAudioOnNotifyEnd;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimNotify", meta=(EditCondition="bFollow", ExposeOnSpawn="TRUE"))
	FName AttachName;

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> PreviewComp;
#endif

};

