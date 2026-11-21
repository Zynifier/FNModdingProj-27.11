// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "SmartObjectRuntime.h"
#include "SmartObjectSubsystem.h"
#include "SmartObjectTypes.h"
#include "UObject/NoExportTypes.h"
#include "Athena/AI/FortAthenaAIRuntimeParametersComponent.h"
#include "FortAthenaAISmartObject.generated.h"

class UGameplayBehavior;
class UGameplayBehaviorConfig;
class UGameplayInteractionSmartObjectBehaviorDefinition;

UENUM(BlueprintType)
enum class EFortAthenaSmartObjectPriority : uint8
{
	Lowest = 0,
	Lower = 1,
	Low = 2,
	BelowNormal = 3,
	Normal = 4,
	AboveNormal = 5,
	High = 6,
	Higher = 7,
	Highest = 8,
	MIN = 0 UMETA(Hidden),
	MAX = 8 UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EFortAthenaSmartObjectUrgency : uint8
{
	Low = 0,
	Normal = 1,
	High = 2,
};

USTRUCT()
struct FAIRuntimeParametersSmartObjectActivityCondition
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FGameplayTagQuery SmartObjectActivityConditionTagQuery;

};

USTRUCT()
struct FAIRuntimeParametersSmartObjectActivityConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FGameplayTagQuery ActivityRequirements;

	UPROPERTY(Transient)
	float MaxDetectionRadius;

	UPROPERTY(Transient)
	float MaxDetectionRadiusSqr;

	UPROPERTY(Transient)
	float ActivityCooldownOnFinished;

	UPROPERTY(Transient)
	float ActivityCooldownOnInterrupted;

};

USTRUCT()
struct FAIRuntimeParametersSmartObjectActivity
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FAIRuntimeParametersSmartObjectActivityCondition SmartObjectActivityCondition;

	UPROPERTY(Transient)
	FAIRuntimeParametersSmartObjectActivityConfig SmartObjectActivityConfig;

	UPROPERTY(Transient)
	uint8 bEnabled : 1;

	UPROPERTY(Transient)
	int32 ActivityID;

	UPROPERTY(Transient)
	float LastUseTimestamp;

	UPROPERTY(Transient)
	float Cooldown;

};

USTRUCT()
struct FFortAthenaAISmartObjectActivityCondition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="SmartObjects", meta=(AllowPrivateAccess="true"))
	FGameplayTagQuery SmartObjectActivityConditionTagQuery;

};

USTRUCT()
struct FFortAthenaAISmartObjectActivityConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="SmartObjects", meta=(AllowPrivateAccess="true"))
	FGameplayTagQuery ActivityRequirements;

	UPROPERTY(EditDefaultsOnly, Category="SmartObjects", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxDetectionRadius;

	UPROPERTY(EditDefaultsOnly, Category="SmartObjects", meta=(AllowPrivateAccess="true"))
	FScalableFloat ActivityCooldownOnFinished;

	UPROPERTY(EditDefaultsOnly, Category="SmartObjects", meta=(AllowPrivateAccess="true"))
	FScalableFloat ActivityCooldownOnInterrupted;

};

USTRUCT(meta=(Hidden))
struct FFortAthenaSmartObjectSlotStateData : public FSmartObjectSlotStateData
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortSmartObjectSlotDefinitionData : public FSmartObjectSlotDefinitionData
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortSmartObjectSlotDefinitionData", meta=(AllowPrivateAccess="true"))
	float CooldownOnFinished;

	UPROPERTY(EditAnywhere, Category="FortSmartObjectSlotDefinitionData", meta=(AllowPrivateAccess="true"))
	float CooldownOnInterrupted;

	UPROPERTY(EditAnywhere, Category="FortSmartObjectSlotDefinitionData", meta=(AllowPrivateAccess="true"))
	float Radius;

	UPROPERTY(EditAnywhere, Category="FortSmartObjectSlotDefinitionData", meta=(AllowPrivateAccess="true"))
	float SlotCooldownOnFinished;

	UPROPERTY(EditAnywhere, Category="FortSmartObjectSlotDefinitionData", meta=(AllowPrivateAccess="true"))
	float SlotCooldownOnInterrupted;

	UPROPERTY(EditAnywhere, Category="FortSmartObjectSlotDefinitionData", meta=(AllowPrivateAccess="true"))
	EFortAthenaSmartObjectPriority Priority;

	UPROPERTY(EditAnywhere, Category="FortSmartObjectSlotDefinitionData", meta=(AllowPrivateAccess="true"))
	EFortAthenaSmartObjectUrgency Urgency;

};

USTRUCT()
struct FSmartObjectBanned
{
	GENERATED_BODY()

};

USTRUCT()
struct FSmartObjectRecentlyUsed
{
	GENERATED_BODY()

};

UCLASS(BlueprintType)
class FORTNITEAI_API UFortAthenaAIRuntimeParameters_SmartObjectBase : public UFortAthenaAIRuntimeParameters
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="RuntimeParameters - SmartObjects")
	bool GetChooseClosestSmartObject() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="RuntimeParameters - SmartObjects")
	void SetChooseClosestSmartObject(const bool bInChooseClosestSmartObject);

private:
	UPROPERTY(Transient)
	uint8 bEnabled : 1;

	UPROPERTY(Transient)
	uint8 bChooseClosestSmartObject : 1;

	UPROPERTY(Transient)
	float UnreachableBanDuration;

	UPROPERTY(Transient)
	float SelectedSmartObjectExpirationDelay;

	UPROPERTY(Transient)
	float GlobalSmartObjectCooldownOnFinished;

	UPROPERTY(Transient)
	float GlobalSmartObjectCooldownOnInterrupted;

	UPROPERTY(Transient)
	TArray<FAIRuntimeParametersSmartObjectActivity> SmartObjectActivities;

	UPROPERTY(Transient)
	TArray<FSmartObjectRecentlyUsed> SmartObjectsMostRecentlyUsed;

	UPROPERTY(Transient)
	TArray<FSmartObjectBanned> SmartObjectsBannedList;

	UPROPERTY(Transient)
	int32 SelectedActivityID;

	UPROPERTY(Transient)
	FSmartObjectRequestResult SelectedResult;

	UPROPERTY(Transient)
	FSmartObjectSlotEntranceHandle SelectedEntranceHandle;

	UPROPERTY(Transient)
	float LastSelectedSmartObjectTimestamp;

	UPROPERTY(Transient)
	FSmartObjectClaimHandle ClaimedHandle;

	UPROPERTY(Transient)
	TObjectPtr<UGameplayBehaviorConfig> BehaviorConfig;

	UPROPERTY(Transient)
	TObjectPtr<UGameplayBehavior> GameplayBehavior;

	UPROPERTY(Transient)
	TObjectPtr<UGameplayInteractionSmartObjectBehaviorDefinition> GameplayInteractionBehaviorDefinition;

	UPROPERTY(Transient)
	float GlobalSmartObjectLastUseTimestamp;

	UPROPERTY(Transient)
	float GlobalSmartObjectCooldown;

	UPROPERTY(Transient)
	int32 ActivitiesIDCount;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class FORTNITEAI_API UFortAthenaAISmartObjectActivity : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="SmartObjects", meta=(AllowPrivateAccess="true"))
	FScalableFloat Enabled;

	UPROPERTY(EditDefaultsOnly, Category="SmartObjects", meta=(AllowPrivateAccess="true"))
	FFortAthenaAISmartObjectActivityCondition SmartObjectActivityCondition;

	UPROPERTY(EditDefaultsOnly, Category="SmartObjects", meta=(AllowPrivateAccess="true"))
	FFortAthenaAISmartObjectActivityConfig SmartObjectActivityConfig;

};

