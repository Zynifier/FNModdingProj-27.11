// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FMPlayspaceScopedSystemManager.generated.h"

class AActor;
enum class ESystemGetResult : uint8;

UENUM(BlueprintType)
enum class ESystemGetResult : uint8
{
	Valid = 0,
	Invalid = 1,
};

USTRUCT(BlueprintType)
struct FFMPlayspaceSystemInfo
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, Blueprintable, ClassGroup=("Harmonix"))
class FMCORERUNTIME_API UFMPlayspaceScopedSystemManager : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(DisplayName="Get Or Create System For Actor", ExpandEnumAsExecs="OutWasValid"))
	static void GetOrCreateSystemForActorBP(TSubclassOf<AActor> SystemClass, AActor* Requester, AActor*& OutActor, ESystemGetResult& OutWasValid);

protected:
	UPROPERTY(EditDefaultsOnly, Category="FMPlayspaceScopedSystemManager")
	TMap<TSubclassOf<AActor>, TSubclassOf<AActor>> VKClassRedirects;

	UPROPERTY(EditDefaultsOnly, Category="FMPlayspaceScopedSystemManager")
	TArray<TSoftClassPtr<AActor>> UEFNNotableActors;

private:
	UFUNCTION(NetMulticast, Reliable)
	void MulticastNewSystemCreated(AActor* PlayspaceActor, TSubclassOf<AActor> SystemClass, AActor* CreatedActor);

};

