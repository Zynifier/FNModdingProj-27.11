// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "GameFramework/GameplayMessageTypes.h"
#include "GameplayEventRouterTypes.h"
#include "AsyncAction_StartListeningToStatefulEvent.generated.h"

class UAsyncAction_StartListeningToStatefulEvent;
class UGameplayEventRouterComponent;
class UObject;
enum class EEventBubblingRule : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAsyncStatefulGameplayEventDelegate, UAsyncAction_StartListeningToStatefulEvent*, ProxyObject);

UCLASS(BlueprintType, meta=(ExposedAsyncProxy="AsyncTaskRef", HasDedicatedAsyncNode))
class GAMEPLAYEVENTROUTER_API UAsyncAction_StartListeningToStatefulEvent : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(CustomThunk, BlueprintCallable, Category="Gameplay Event Router", meta=(CustomStructureParam="OutPayload"))
	bool GetPayload(UPARAM(ref) int32& OutPayload);
	DECLARE_FUNCTION(execGetPayload);

	UFUNCTION(BlueprintCallable, Category="Gameplay Event Router", meta=(AdvancedDisplay="EventBubblingRule", BlueprintInternalUseOnly="true", WorldContext="WorldContextObject"))
	static UAsyncAction_StartListeningToStatefulEvent* StartListeningToStatefulEvent(UObject* WorldContextObject, UGameplayEventRouterComponent* Target, UObject* EventType, UObject* Context = nullptr, EEventBubblingRule EventBubblingRule = EEventBubblingRule::None);

	UFUNCTION(BlueprintCallable, Category="Gameplay Event Router", meta=(AdvancedDisplay="EventBubblingRule", BlueprintInternalUseOnly="true", WorldContext="WorldContextObject"))
	static UAsyncAction_StartListeningToStatefulEvent* StartListeningToStatefulEventBackwardsCompatible(UObject* WorldContextObject, FEventMessageTag Channel, UGameplayEventRouterComponent* Target, UObject* EventType, UObject* Context = nullptr, EEventBubblingRule EventBubblingRule = EEventBubblingRule::None);

	UFUNCTION(BlueprintCallable, Category="Gameplay Event Router")
	void StopListeningToStatefulEvent();

	UPROPERTY(BlueprintAssignable)
	FAsyncStatefulGameplayEventDelegate OnEventReceived;

	UPROPERTY(BlueprintAssignable)
	FAsyncStatefulGameplayEventDelegate OnSavedEventStateExists;

	UPROPERTY(BlueprintAssignable)
	FAsyncStatefulGameplayEventDelegate OnEventStateCleared;

};

