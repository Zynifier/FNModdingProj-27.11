// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameFramework/GameplayMessageTypes.h"
#include "GameplayEventRouterTypes.h"
#include "GameplayEventRouterSubsystem.generated.h"

class AActor;
class UGameplayEventRouterComponent;
class UObject;

UCLASS()
class GAMEPLAYEVENTROUTER_API UGameplayEventRouterSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Gameplay Event Router", meta=(WorldContext="WorldContextObject"))
	static void ClearEventStateBackwardCompatible(UObject* WorldContextObject, FEventMessageTag Channel, UGameplayEventRouterComponent* Target, const UObject* EventType);

	UFUNCTION(BlueprintCallable, Category="Gameplay Event Router", meta=(WorldContext="WorldContextObject"))
	static void ClearEventStateByContextBackwardCompatible(UObject* WorldContextObject, FEventMessageTag Channel, UGameplayEventRouterComponent* Target, const UObject* EventType, const UObject* Context);

	UFUNCTION(BlueprintCallable, Category="Gameplay Event Router")
	static UGameplayEventRouterComponent* GetEventRouter(UClass* Scope, AActor* ContextActor);

	UFUNCTION(BlueprintPure, Category="Gameplay Event Router", meta=(WorldContext="WorldContextObject"))
	static UGameplayEventRouterComponent* GetGlobalEventRouter(const UObject* WorldContextObject);

	UFUNCTION(CustomThunk, BlueprintCallable, Category="Gameplay Event Router", meta=(AllowAbstract="false", CustomStructureParam="EventData", DisplayName="Broadcast Event Backward Compatible", WorldContext="WorldContextObject"))
	static bool K2_BroadcastEventBackwardCompatible(UObject* WorldContextObject, UGameplayEventRouterComponent* Target, FEventMessageTag Channel, const int32& EventData, UPARAM(DisplayName="Context") UObject* EventContext = nullptr);
	DECLARE_FUNCTION(execK2_BroadcastEventBackwardCompatible);

	UFUNCTION(CustomThunk, BlueprintCallable, Category="Gameplay Event Router", meta=(AllowAbstract="false", CustomStructureParam="EventData", DisplayName="Broadcast Stateful Event Backward Compatible", WorldContext="WorldContextObject"))
	static bool K2_BroadcastStatefulEventBackwardCompatible(UObject* WorldContextObject, UGameplayEventRouterComponent* Target, FEventMessageTag Channel, const int32& EventData, UPARAM(DisplayName="Context") UObject* EventContext = nullptr);
	DECLARE_FUNCTION(execK2_BroadcastStatefulEventBackwardCompatible);

protected:
	UPROPERTY()
	TArray<FGameplayEventGlobalRouterPendingListenerData> PendingGlobalRouterListenerDatas;

};

