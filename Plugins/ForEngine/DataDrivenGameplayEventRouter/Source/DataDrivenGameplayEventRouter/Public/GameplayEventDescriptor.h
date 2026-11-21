// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameplayEventDescriptor.generated.h"

class AActor;
class UObject;

UENUM()
enum class EGameplayEventNetPolicy : uint8
{
	/** Events can only be bound and broadcast on the server (determined by whether the RouterContextActor has authority). */
	ServerOnly = 0,
	/** Events can be bound and broadcast on both the client and server. */
	ClientOrServer = 1,
};

USTRUCT()
struct FGameplayEventDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Gameplay Event")
	TObjectPtr<UObject> EventType;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay Event")
	bool bIsStateful;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Gameplay Event")
	EGameplayEventNetPolicy NetPolicy;

};

USTRUCT(BlueprintType, meta=(DisplayName="Gameplay Event"))
struct DATADRIVENGAMEPLAYEVENTROUTER_API FGameplayEventDescriptor
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TObjectPtr<UObject> EventType_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	bool bIsStateful_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	EGameplayEventNetPolicy NetPolicy_DEPRECATED;
#endif

};

UCLASS(MinimalAPI)
class UGameplayEventDescriptorLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

private:
	UFUNCTION(CustomThunk, BlueprintCallable, Category="Gameplay Event", meta=(AdvancedDisplay="EventRouterScope,RouterContextActor", CustomStructureParam="Event", DefaultToSelf="EventContext"))
	static bool BroadcastEvent(const FGameplayEventDescriptor& EventDescriptor, UObject* EventContext, const int32& Event, UClass* EventRouterScope = nullptr, AActor* RouterContextActor = nullptr);
	DECLARE_FUNCTION(execBroadcastEvent);

};

