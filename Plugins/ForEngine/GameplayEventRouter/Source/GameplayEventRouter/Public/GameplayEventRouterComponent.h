// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/GameFrameworkInitStateInterface.h"
#include "GameplayEventRouterTypes.h"
#include "GameplayEventRouterComponent.generated.h"

class UObject;

UCLASS(NotBlueprintable)
class GAMEPLAYEVENTROUTER_API UGameplayEventRouterComponent : public UActorComponent, public IGameFrameworkInitStateInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Gameplay Event Router")
	void ClearEventState(const UObject* EventType);

	UFUNCTION(BlueprintCallable, Category="Gameplay Event Router")
	void ClearEventStateByContext(const UObject* EventType, const UObject* Context);

	UFUNCTION(BlueprintPure, Category="Gameplay Event Router")
	bool HasValidEventState(const UObject* EventType, const UObject* Context = nullptr) const;

	UFUNCTION(BlueprintCallable)
	void StopListeningToEvent(UPARAM(ref) FGameplayEventListenerHandle& HandleToRemove);

protected:
	UFUNCTION(CustomThunk, BlueprintCallable, Category="Gameplay Event Router", meta=(AllowAbstract="false", CustomStructureParam="EventData", DisplayName="Broadcast Event"))
	bool K2_BroadcastEvent(const int32& EventData, UPARAM(DisplayName="Context") UObject* EventContext = nullptr);
	DECLARE_FUNCTION(execK2_BroadcastEvent);

	UFUNCTION(CustomThunk, BlueprintCallable, Category="Gameplay Event Router", meta=(AllowAbstract="false", CustomStructureParam="EventData", DisplayName="Broadcast Stateful Event"))
	bool K2_BroadcastStatefulEvent(const int32& EventData, UPARAM(DisplayName="Context") UObject* EventContext = nullptr);
	DECLARE_FUNCTION(execK2_BroadcastStatefulEvent);

};

