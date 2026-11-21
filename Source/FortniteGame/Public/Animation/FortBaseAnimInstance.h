// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "GameplayTagContainer.h"
#include "Animation/BoneSetInterface.h"
#include "Animation/FortAnimTagProperty.h"
#include "FortBaseAnimInstance.generated.h"

class AFortPawn;
class UAnimSequenceBase;
class UFortAnimInputEvent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FGameplayTagNotifyDelegate, UAnimSequenceBase*, Animation, FGameplayTag, NotifyTag);

UCLASS(Config=Game, MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortBaseAnimInstance : public UAnimInstance, public IBoneSetInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="BoneSets")
	TMap<FGameplayTag, FBoneSet> BoneSets;

	UPROPERTY(EditDefaultsOnly, Category="FortBaseAnimInstance")
	TArray<FAnimTagProperty> AnimPropertyGameplayTagBindings;

	UPROPERTY(BlueprintAssignable)
	FGameplayTagNotifyDelegate OnGameplayTagNotifyBegin;

	UPROPERTY(BlueprintAssignable)
	FGameplayTagNotifyDelegate OnGameplayTagNotifyEnd;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void BlueprintProcessAnimInputEvent(const UFortAnimInputEvent* AnimInputEvent);

	UFUNCTION(BlueprintPure, Category="Animation")
	FORTNITEGAME_API AFortPawn* TryGetFortPawn() const;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortAnimInputEvent>> AnimInputEventList;

};

