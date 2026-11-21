// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Building/BuildingGameplayActor.h"
#include "DynamicStructures/ScriptedObjectMovementDynamicPathContext.h"
#include "StaticPaths/ScriptedObjectMovementStaticPathStepData.h"
#include "ScriptedObjectMovementMovableObjectBase.generated.h"

class AScriptedObjectMovement_StaticPath;
class UActorComponent;
class UFortScriptedObjectMovement_SlotDefinition;
class UStaticMesh;
class UStaticMeshComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class SOMRUNTIME_API AFortScriptedObjectMovement_MovableObjectBase : public ABuildingGameplayActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category="Static Path Following")
	void BeginMovingToStaticPathNode(const FScriptedObjectMovement_StaticPathStepData& StepData);

	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	bool BlockOverlappingStaticPathSteps() const;

	UFUNCTION(NetMulticast, Reliable)
	void Cheat_NetMulticast_SendDebugTimerInfo(const float ServerTimeWhenQueryInvoked, const float RemainingTime);

	UFUNCTION(Category="Editor", meta=(CallInEditor="true"))
	void CheatDrawKeyframes();

	UFUNCTION(BlueprintCallable, Category="Dynamic Path Following")
	void ConfigureStaticMeshToSlotDefinition(UFortScriptedObjectMovement_SlotDefinition* SlotDefinition, UStaticMeshComponent* StaticMeshComponent);

	UFUNCTION(Category="Editor", meta=(CallInEditor="true"))
	void Editor_ClearResetObjectLocation();

	UFUNCTION(Category="Editor", meta=(CallInEditor="true"))
	void Editor_DebugLogStaticPathTravelIndex();

	UFUNCTION(Category="Editor", meta=(CallInEditor="true"))
	void Editor_NextStep();

	UFUNCTION(Category="Editor", meta=(CallInEditor="true"))
	void Editor_PreviousStep();

	UFUNCTION(Category="Editor", meta=(CallInEditor="true"))
	void Editor_ResetObject();

	UFUNCTION(Category="Editor", meta=(CallInEditor="true"))
	void Editor_TryJumpToStartStep();

	UFUNCTION(BlueprintNativeEvent, Category="Dynamic Path Following")
	UStaticMeshComponent* GetScriptedObjectStaticMeshComponent();

	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	void GetStaticPathTravelingBounds(FVector& OutBoxExtent) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	float GetStaticPathZOffsetHeight() const;

	UFUNCTION(BlueprintNativeEvent, Category="Dynamic Path Following")
	void HandleSlotDefinitionSlotted(UFortScriptedObjectMovement_SlotDefinition* SlotDefinition);

	UFUNCTION(BlueprintCallable, Category="Static Path Following")
	void NotifyStaticPathStepComplete(bool bReachedBeginPlaySkipStep = false);

	UFUNCTION(BlueprintCallable, Category="Navigation")
	void SetCanEverAffectNavigation(bool bCanEverAffectNavigation, UActorComponent* TargetActorComponent);

	UPROPERTY(EditAnywhere, Transient, Category="Editor")
	int32 Editor_SkipMasterPathIndex;

	UPROPERTY(EditAnywhere, Transient, Category="Editor")
	int32 Editor_SkipSubPathIndex;

	UPROPERTY(EditAnywhere, Transient, Category="Editor", meta=(ClampMax="1000", ClampMin="1"))
	int32 Editor_NumStepsPerClick;

	UPROPERTY(EditInstanceOnly, Category="Static Path Following")
	bool bDebugStaticMovement;

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortScriptedObjectMovement_MovableObjectBase")
	TObjectPtr<UStaticMesh> ScriptedObjectMesh;

	UPROPERTY(VisibleAnywhere, Category="FortScriptedObjectMovement_MovableObjectBase")
	bool bWaitingForBeginPlaySkip;

	UPROPERTY(VisibleInstanceOnly, Category="Static Path Following")
	TObjectPtr<AScriptedObjectMovement_StaticPath> StaticFollowPath;

private:
	UFUNCTION()
	void OnRep_CurrentStepData();

	UPROPERTY(Transient)
	TObjectPtr<UFortScriptedObjectMovement_SlotDefinition> AssignedSlotDefinition;

	UPROPERTY(Transient)
	FScriptedObjectMovement_DynamicPathContext MovementPath;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_CurrentStepData, Category="Static Path Following", meta=(AllowPrivateAccess="true"))
	FScriptedObjectMovement_StaticPathStepData CurrentStepData;

};

