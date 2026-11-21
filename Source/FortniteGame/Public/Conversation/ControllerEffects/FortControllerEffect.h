// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "FortControllerEffect.generated.h"

class AActor;
class AController;

USTRUCT(BlueprintType)
struct FEffectRequestContext
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="EffectRequestContext")
	TObjectPtr<AActor> EffectReceivingActor;

	UPROPERTY(BlueprintReadOnly, Category="EffectRequestContext")
	TObjectPtr<AController> EffectReceivingController;

	UPROPERTY(BlueprintReadOnly, Category="EffectRequestContext")
	TObjectPtr<AController> InstigatingController;

	UPROPERTY(BlueprintReadOnly, Category="EffectRequestContext")
	TObjectPtr<AActor> InstigatingActor;

	UPROPERTY(BlueprintReadOnly, Category="EffectRequestContext")
	FGameplayTagContainer SourceTags;

	UPROPERTY(BlueprintReadOnly, Category="EffectRequestContext")
	FGameplayTagContainer TargetTags;

	UPROPERTY(BlueprintReadOnly, Category="EffectRequestContext")
	FGameplayTagContainer ContextTags;

};

UCLASS(Abstract, EditInlineNew, BlueprintType, Blueprintable)
class UFortControllerEffect : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	void ApplyEffect(const FEffectRequestContext& RequestContext) const;

protected:
	UFUNCTION(BlueprintNativeEvent)
	void ApplyEffectInternal(const FEffectRequestContext& RequestContext) const;

};

