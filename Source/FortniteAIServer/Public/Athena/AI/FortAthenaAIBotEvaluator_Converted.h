// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_Movement.h"
#include "FortAthenaAIBotEvaluator_Converted.generated.h"

class AFortPawn;
class UEnvQuery;
class UFortAthenaAIRuntimeParameters_AIBotConvert;
enum class EUnconvertReason : uint8;

USTRUCT()
struct FMimicConverterAbilityData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="MimicConverterAbilityData")
	FGameplayTagQuery RequiredConverterAbilityTags;

	UPROPERTY(EditAnywhere, Category="MimicConverterAbilityData")
	FGameplayTagContainer AbilitiesToApply;

};

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_Converted : public UFortAthenaAIBotEvaluator_Movement
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnConvertedEvent(AFortPawn* InstigatorPawn, AFortPawn* ConvertedPawn);

	UFUNCTION()
	void OnUnconvertedEvent(AFortPawn* UnconvertedPawn, const EUnconvertReason UnconvertReason);

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName ShouldMoveTowardsConverterName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName ShouldTeleportTowardsConverterName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName ConvertedAllowPatrolAroundName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName ConvertedAllowScanAroundWhenWaitingName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName ConvertedDestinationName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName CrouchExecutionStatusName;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FVector TeleportLocationProjectionExtent;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FVector MovingFromLosLocationProjectionExtent;

	UPROPERTY(EditAnywhere, Category="FortAthenaAIBotEvaluator_Converted", meta=(AllowPrivateAccess="true"))
	FScalableFloat AmountOfTimesNonHostilePawnNeedsToBeDamagedForTargeting;

	UPROPERTY(EditAnywhere, Category="FortAthenaAIBotEvaluator_Converted", meta=(AllowPrivateAccess="true"))
	FScalableFloat TimeToTrackDamagedActors;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat NearbyPlayerDistanceForTeleportTowardsConverter;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat PlayerFOVForNearbyPlayersVisibility;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UEnvQuery> TeleportToConverterQueryTemplate;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	TEnumAsByte<EEnvQueryRunMode::Type> TeleportToConverterRunMode;

	UPROPERTY(EditAnywhere, Category="Convert", meta=(AllowPrivateAccess="true"))
	TArray<FMimicConverterAbilityData> AbilitiesToMimic;

	UPROPERTY(Transient)
	TObjectPtr<AFortPawn> ConverterPawn;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIRuntimeParameters_AIBotConvert> CachedAIBotConvertParameters;

};

