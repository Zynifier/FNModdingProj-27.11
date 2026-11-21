// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "StateTransitionController.generated.h"

class UObject;
enum class EStateTransitionControlEvent : uint8;
enum class EStateTransitionPauseRequestHandleClearType : uint8;

UENUM(BlueprintType)
enum class EStateTransitionControlEvent : uint8
{
	/* 
	 *  When a need for a pause has been confirmed - this event allows you to add your own requests to a transition pause which you didn't cause.
	 *	For example, if you want to spawn a particle if (and ONLY if) another system is going to prevent the immediate change to a different state.
	 */
	OnStateTransitionPaused = 0,
	// When the state transition has occurred.

	OnStateTransitionComplete = 1,
	Count = 2 UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EStateTransitionPauseRequestHandleClearType : uint8
{
	// Clear the request only after all handles for the request have been cleared 

	ClearWhenAllHandlesAreRemoved = 0,
	// Clear the request right away, even if other handles are active (useful if other copies might exist)

	ClearRightAway = 1,
};

USTRUCT(BlueprintType)
struct FStateTransitionControllerHandle
{
	GENERATED_BODY()

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FStateTransitionEventMulti, FStateTransitionControllerHandle, TransitionController);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FStateTransitionEvent, FStateTransitionControllerHandle, TransitionController);

USTRUCT(BlueprintType)
struct FStateTransitionPauseRequestHandle
{
	GENERATED_BODY()

};

UCLASS(BlueprintType)
class UStateTransitionControlLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static void AddPauseRequest(const FStateTransitionControllerHandle& Controller, UPARAM(ref) FStateTransitionPauseRequestHandle& Handle);

	UFUNCTION(BlueprintCallable)
	static void ClearPauseRequest(UPARAM(ref) FStateTransitionPauseRequestHandle& Handle, EStateTransitionPauseRequestHandleClearType ClearType);

	UFUNCTION(BlueprintPure)
	static bool IsStateTransitionPaused(const FStateTransitionControllerHandle& Controller);

	UFUNCTION(BlueprintCallable)
	static void RegisterEvent(const FStateTransitionControllerHandle& Controller, FStateTransitionEvent Event, EStateTransitionControlEvent Type);

	UFUNCTION(BlueprintCallable)
	static void RemoveAllEvents(const FStateTransitionControllerHandle& Controller, UObject* Object, EStateTransitionControlEvent Type);

	UFUNCTION(BlueprintCallable)
	static void RemoveEvent(const FStateTransitionControllerHandle& Controller, FStateTransitionEvent Event, EStateTransitionControlEvent Type);

	UFUNCTION(BlueprintCallable)
	static void ResetPauseRequestHandle(UPARAM(ref) FStateTransitionPauseRequestHandle& Handle);

};

