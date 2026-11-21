// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/StateTreeTaskBlueprintBase.h"
#include "Engine/EngineTypes.h"
#include "Athena/AI/StateTrees/Tasks/FortAthenaStateTreeTaskTypes.h"
#include "FortAthenaAttachToActorStateTreeTask.generated.h"

class AActor;
class AFortPawn;

UCLASS(meta=(DisplayName="(Fortnite) Attach to Actor"))
class UFortAthenaAttachToActorStateTreeTask : public UStateTreeTaskBlueprintBase
{
	GENERATED_BODY()

public:
	UFortAthenaAttachToActorStateTreeTask(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(EditAnywhere, Category="Context")
	TObjectPtr<AActor> Actor;

	UPROPERTY(EditAnywhere, Category="Context")
	TObjectPtr<AActor> TargetActor;

	UPROPERTY(EditAnywhere, Category="Parameter")
	EFortAthenaStateTreeTaskFeatureExecutionMode AttachExecutionMode;

	UPROPERTY(EditAnywhere, Category="Parameter", meta=(EditCondition="AttachExecutionMode != EFortAthenaStateTreeTaskFeatureExecutionMode::DoNotExecute"))
	bool bHandleAthenaMovComponent;

	UPROPERTY(EditAnywhere, Category="Parameter", meta=(EditCondition="AttachExecutionMode != EFortAthenaStateTreeTaskFeatureExecutionMode::DoNotExecute"))
	bool bSetPhysicsToQueryOnlyWhileAttached;

	UPROPERTY(EditAnywhere, Category="Parameter", meta=(EditCondition="AttachExecutionMode != EFortAthenaStateTreeTaskFeatureExecutionMode::DoNotExecute"))
	bool bTryToAttachToSkeletalMeshOnTargetActor;

	UPROPERTY(EditAnywhere, Category="Parameter", meta=(EditCondition="AttachExecutionMode != EFortAthenaStateTreeTaskFeatureExecutionMode::DoNotExecute && bTryToAttachToSkeletalMeshOnTargetActor"))
	bool bChangeBaseToSkeletalMeshOnTargetActor;

	UPROPERTY(EditAnywhere, Category="Parameter", meta=(EditCondition="AttachExecutionMode != EFortAthenaStateTreeTaskFeatureExecutionMode::DoNotExecute"))
	EAttachmentRule AttachmentLocationRule;

	UPROPERTY(EditAnywhere, Category="Parameter", meta=(EditCondition="AttachExecutionMode != EFortAthenaStateTreeTaskFeatureExecutionMode::DoNotExecute"))
	EAttachmentRule AttachmentRotationRule;

	UPROPERTY(EditAnywhere, Category="Parameter", meta=(EditCondition="AttachExecutionMode != EFortAthenaStateTreeTaskFeatureExecutionMode::DoNotExecute"))
	EAttachmentRule AttachmentScaleRule;

	UPROPERTY(EditAnywhere, Category="Parameter", meta=(EditCondition="AttachExecutionMode != EFortAthenaStateTreeTaskFeatureExecutionMode::DoNotExecute"))
	bool bWeldSimulatedBodiesOnAttach;

	UPROPERTY(EditAnywhere, Category="Parameter", meta=(EditCondition="AttachExecutionMode != EFortAthenaStateTreeTaskFeatureExecutionMode::DoNotExecute"))
	FName AttachmentSocketName;

	UPROPERTY(EditAnywhere, Category="Parameter")
	EFortAthenaStateTreeTaskFeatureExecutionMode DetachExecutionMode;

	UPROPERTY(EditAnywhere, Category="Parameter", meta=(EditCondition="DetachExecutionMode != EFortAthenaStateTreeTaskFeatureExecutionMode::DoNotExecute"))
	bool bForceChangeBaseOnDetach;

	UPROPERTY(EditAnywhere, Category="Parameter", meta=(EditCondition="DetachExecutionMode != EFortAthenaStateTreeTaskFeatureExecutionMode::DoNotExecute"))
	EDetachmentRule DetachmentLocationRule;

	UPROPERTY(EditAnywhere, Category="Parameter", meta=(EditCondition="DetachExecutionMode != EFortAthenaStateTreeTaskFeatureExecutionMode::DoNotExecute"))
	EDetachmentRule DetachmentRotationRule;

	UPROPERTY(EditAnywhere, Category="Parameter", meta=(EditCondition="DetachExecutionMode != EFortAthenaStateTreeTaskFeatureExecutionMode::DoNotExecute"))
	EDetachmentRule DetachmentScaleRule;

	UPROPERTY(EditAnywhere, Category="Parameter", meta=(EditCondition="DetachExecutionMode != EFortAthenaStateTreeTaskFeatureExecutionMode::DoNotExecute"))
	bool bCallModifyOnDetach;

	UPROPERTY(EditAnywhere, Category="Parameter", meta=(EditCondition="AttachExecutionMode == EFortAthenaStateTreeTaskFeatureExecutionMode::ExecuteOnEnter && DetachExecutionMode == EFortAthenaStateTreeTaskFeatureExecutionMode::ExecuteOnExit"))
	bool bHandleLaunchCharacter;

	UPROPERTY(EditAnywhere, Category="Output")
	bool bHasHandledLaunchCharacter;

	UPROPERTY(Transient)
	TObjectPtr<AFortPawn> FortPawnActor;

};

