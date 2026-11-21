// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Misc/Timespan.h"
#include "ScriptedObjectMovementStaticPathTool.generated.h"

class AFortScriptedObjectMovement_MovableObjectBase;
class UFortAsyncAction_CalendarMultiEventWatcher;
class UScriptedObjectMovement_CalendarCheatDefinition;
class USplineComponent;

USTRUCT()
struct FScriptedObjectMovement_StaticPathSplineInputKeyData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditInstanceOnly, Category="ScriptedObjectMovement_StaticPathSplineInputKeyData")
	bool bLockGeneratedData;

	UPROPERTY(EditInstanceOnly, Category="ScriptedObjectMovement_StaticPathSplineInputKeyData", meta=(DisplayName="MoveCalendarEvent"))
	FString CalendarEvent;

	UPROPERTY(EditInstanceOnly, Category="ScriptedObjectMovement_StaticPathSplineInputKeyData")
	FString PauseCalendarEvent;

};

USTRUCT()
struct FScriptedObjectMovement_StepMetaData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bSkipStep;

};

USTRUCT()
struct FScriptedObjectMovement_StaticPathTravelerData
{
	GENERATED_BODY()

public:
	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<TObjectPtr<USplineComponent>> GeneratedSplinesArray;

	UPROPERTY()
	TArray<FScriptedObjectMovement_StepMetaData> StepMetaData;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<USplineComponent> EnterSpline;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<USplineComponent> ExitSpline;

	UPROPERTY(EditInstanceOnly, Category="ScriptedObjectMovement_StaticPathTravelerData")
	TObjectPtr<AFortScriptedObjectMovement_MovableObjectBase> PathTraveler;

	UPROPERTY(EditInstanceOnly, Category="ScriptedObjectMovement_StaticPathTravelerData")
	int32 TravelOrder;

	UPROPERTY(EditInstanceOnly, Category="ScriptedObjectMovement_StaticPathTravelerData")
	float LateralOffset;

	UPROPERTY(EditInstanceOnly, Category="ScriptedObjectMovement_StaticPathTravelerData")
	bool bLocked;

	UPROPERTY(EditInstanceOnly, Category="ScriptedObjectMovement_StaticPathTravelerData")
	bool bLockEnterSpline;

	UPROPERTY(EditInstanceOnly, Category="ScriptedObjectMovement_StaticPathTravelerData")
	bool bLockExitSpline;

	UPROPERTY(VisibleInstanceOnly, Category="ScriptedObjectMovement_StaticPathTravelerData")
	FVector TravelerBounds;

};

USTRUCT()
struct FStaticPathCalendarSplinePointGroup
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, Blueprintable)
class SOMRUNTIME_API AScriptedObjectMovement_StaticPath : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(Category="ScriptedObjectMovementStaticPath", meta=(CallInEditor="true"))
	void GeneratePathData();

	UFUNCTION(Category="ScriptedObjectMovementStaticPath", meta=(CallInEditor="true"))
	void LockAllPathNodesFromBeingRegenerated();

	UFUNCTION(Category="ScriptedObjectMovementStaticPath", meta=(CallInEditor="true"))
	void UnlockAllPathsFromBeingRegenerated();

	UPROPERTY(EditAnywhere, Category="ScriptedObjectMovement_StaticPath")
	TSoftObjectPtr<UScriptedObjectMovement_CalendarCheatDefinition> CheatCalendarEventDefinition;

protected:
	UFUNCTION()
	virtual void HandleCalendarEventActive(const FString& EventName, FTimespan TimeUntilEnd, FTimespan TimeSinceBegin, float TimeSpanRatio);

	UFUNCTION()
	virtual void HandleCalendarEventEnded(const FString& EventName, FTimespan TimeUntilEnd, FTimespan TimeSinceBegin, float TimeSpanRatio);

	UFUNCTION()
	virtual void HandleCalendarEventUpdated(const FString& EventName, FTimespan TimeUntilEnd, FTimespan TimeSinceBegin, float TimeSpanRatio);

	UPROPERTY(VisibleAnywhere, Export, Category="ScriptedObjectMovement_StaticPath", meta=(EditInline="true"))
	TObjectPtr<USplineComponent> MasterSplinePath;

	UPROPERTY(EditAnywhere, Category="ScriptedObjectMovementStaticPath")
	TArray<FScriptedObjectMovement_StaticPathTravelerData> PathTravelers;

	UPROPERTY(EditInstanceOnly, Category="ScriptedObjectMovementStaticPath")
	TArray<FScriptedObjectMovement_StaticPathSplineInputKeyData> SplineData;

	UPROPERTY(EditAnywhere, Category="ScriptedObjectMovement_StaticPath", meta=(ClampMin="1.000000"))
	float StepSpacingDistance;

	UPROPERTY(EditAnywhere, Category="ScriptedObjectMovement_StaticPath")
	FGameplayTag MovementStyleTag;

	UPROPERTY(EditAnywhere, Category="ScriptedObjectMovement_StaticPath")
	FString EnterSplineCalendarEvent;

	UPROPERTY(EditAnywhere, Category="ScriptedObjectMovement_StaticPath")
	FString ExitSplineCalendarEvent;

	UPROPERTY(Transient)
	TArray<FStaticPathCalendarSplinePointGroup> OrderedCalendarEventPointGroups;

	UPROPERTY()
	TObjectPtr<UFortAsyncAction_CalendarMultiEventWatcher> CalendarWatcherAction;

};

