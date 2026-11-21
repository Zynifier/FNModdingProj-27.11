// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortAthenaAIEvaluator.generated.h"

class AAIController;
class IFortAthenaAILODSettings;
class UBehaviorTreeComponent;
class UBlackboardKeyAccessValidator;
class UNavigationQueryFilter;

UENUM(BlueprintType)
enum class EExecutionStatus : uint8
{
	ExecutionError = 0,
	ExecutionDenied = 1,
	ExecutionSuccess = 2,
	// Keep these two at the end

	ExecutionPending = 3,
	ExecutionAllowed = 4,
};

UCLASS(Transient)
class UBlackboardKeyAccessValidator : public UObject
{
	GENERATED_BODY()

};

UCLASS(Abstract, MinimalAPI)
class UFortAthenaAIEvaluator : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UBehaviorTreeComponent> CachedOwnerComp;

	UPROPERTY(Transient)
	TObjectPtr<AAIController> CachedAIController;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nav")
	TSubclassOf<UNavigationQueryFilter> OverrideNavigationFilterClass;

private:
	UPROPERTY(EditAnywhere, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName ExecutionStatusName;

	UPROPERTY(Transient)
	TScriptInterface<IFortAthenaAILODSettings> CachedLODSettingsInterface;

	UPROPERTY(Transient)
	TObjectPtr<UBlackboardKeyAccessValidator> KeyAccessValidator;

};

