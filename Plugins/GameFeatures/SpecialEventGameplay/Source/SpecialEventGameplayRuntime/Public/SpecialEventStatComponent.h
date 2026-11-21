// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "SpecialEventStatComponent.generated.h"

class AActor;
class USpecialEventStatComponent;

USTRUCT(BlueprintType)
struct FSpecialEventStatDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="SpecialEventStatDefinition")
	FGameplayTag LookupTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="SpecialEventStatDefinition")
	float Min;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="SpecialEventStatDefinition")
	float Max;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="SpecialEventStatDefinition")
	float DefaultValue;

};

USTRUCT(BlueprintType)
struct FSpecialEventStatArrayEntry : public FFastArraySerializerItem
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, NotReplicated, Export, Category="SpecialEventStatArrayEntry", meta=(AllowPrivateAccess, EditInline="true"))
	TObjectPtr<USpecialEventStatComponent> StatComponent;

	UPROPERTY(BlueprintReadOnly, NotReplicated, Category="SpecialEventStatArrayEntry", meta=(AllowPrivateAccess))
	TObjectPtr<AActor> Owner;

	UPROPERTY()
	int32 StatDefinitionIndex;

	UPROPERTY(BlueprintReadOnly, NotReplicated, Category="SpecialEventStatArrayEntry", meta=(AllowPrivateAccess, DisplayName="StatDefinition"))
	FSpecialEventStatDefinition StatDefinitionCopy;

	UPROPERTY(BlueprintReadOnly, Category="SpecialEventStatArrayEntry", meta=(AllowPrivateAccess))
	float Value;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSpecialEventStatComponent_OnValueChanged, const FSpecialEventStatArrayEntry&, Stat);

USTRUCT()
struct FSpecialEventStatArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FSpecialEventStatArrayEntry> Stats;

protected:
	UPROPERTY(NotReplicated, Export, meta=(EditInline="true"))
	TObjectPtr<USpecialEventStatComponent> StatComponent;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Activation", "Collision", "ComponentTick", "Cooking"), meta=(BlueprintSpawnableComponent))
class USpecialEventStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="SpecialEventStat")
	static void AdjustSpecialEventStat(AActor* Actor, const FGameplayTag LookupTag, const float Adjustment);

	UFUNCTION(BlueprintCallable, Category="SpecialEventStat")
	bool AdjustStat(const FGameplayTag LookupTag, const float Adjustment, const bool bLogError = true);

	UFUNCTION(BlueprintCallable, Category="SpecialEventStat")
	static const FSpecialEventStatArrayEntry& GetSpecialEventStat(bool& bOutValid, const AActor* Actor, const FGameplayTag LookupTag);

	UFUNCTION(BlueprintCallable, Category="SpecialEvent")
	const FSpecialEventStatArrayEntry& GetStat(bool& bOutValid, const FGameplayTag LookupTag);

	UPROPERTY(BlueprintAssignable)
	FSpecialEventStatComponent_OnValueChanged OnValueChangedDelegate;

private:
	UPROPERTY(EditDefaultsOnly, Category="SpecialEventStatComponent")
	TArray<FSpecialEventStatDefinition> StatDefinitions;

	UPROPERTY(Replicated)
	FSpecialEventStatArray StatFastArray;

};

