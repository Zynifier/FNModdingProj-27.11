// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_Movement.h"
#include "FortAthenaAIBotEvaluator_SmartObjects.generated.h"

class UCurveFloat;
class UFortAthenaAIRuntimeParameters_SmartObjectBase;
class USmartObjectSlotValidationFilter;
class USmartObjectSubsystem;

USTRUCT()
struct FSmartObjectActivityResult
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_SmartObjects : public UFortAthenaAIBotEvaluator_Movement
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIRuntimeParameters_SmartObjectBase> SmartObjectRuntimeParameters;

	UPROPERTY(Transient)
	TObjectPtr<USmartObjectSubsystem> SmartObjectSubsystem;

	UPROPERTY(EditAnywhere, Category="FortAthenaAIBotEvaluator_SmartObjects", meta=(AllowPrivateAccess="true"))
	bool bEvaluateSOValidityAfterChosen;

	UPROPERTY(EditAnywhere, Category="FortAthenaAIBotEvaluator_SmartObjects", meta=(AllowPrivateAccess="true"))
	bool bEnableEntryLocationsSupport;

	UPROPERTY(EditAnywhere, Category="FortAthenaAIBotEvaluator_SmartObjects", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UCurveFloat> DistanceToWeightCurveForSlotPicking;

	UPROPERTY(EditAnywhere, Category="FortAthenaAIBotEvaluator_SmartObjects", meta=(AllowPrivateAccess="true", EditCondition="bEnableEntryLocationsSupport"))
	TSubclassOf<USmartObjectSlotValidationFilter> OverridenFilterClassForEntryPoints;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	TArray<FName> ExecutionStatusesToCheckForAllowToAvoidGoingToSOKeyNames;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName SmartObjectExecutionStatusKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName SmartObjectMovementStateKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName SmartObjectDestinationKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName SmartObjectDestinationRotationKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName SmartObjectShouldMoveKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName SmartObjectUrgencyKeyName;

};

