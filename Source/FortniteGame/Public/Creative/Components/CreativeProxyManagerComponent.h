// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/OnlineReplStructs.h"
#include "CreativeProxyManagerComponent.generated.h"

class ACreativePlayerReplicationProxy;
class APlayerController;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnProxyDataChanged, ACreativePlayerReplicationProxy*, ProxyData);

UCLASS(ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class FORTNITEGAME_API UCreativeProxyManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void DestroyAllProxies();

	UFUNCTION(BlueprintCallable)
	void DestroyProxyForPlayer(APlayerController* PlayerController);

	UFUNCTION(BlueprintCallable)
	void DestroyProxyForUniqueNetId(const FUniqueNetIdRepl& Id);

	UFUNCTION(BlueprintCallable)
	ACreativePlayerReplicationProxy* GetProxyForPlayer(APlayerController* PlayerController);

	UFUNCTION(BlueprintCallable)
	ACreativePlayerReplicationProxy* GetProxyForUniqueNetId(const FUniqueNetIdRepl& Id);

	UPROPERTY(BlueprintAssignable)
	FOnProxyDataChanged OnProxyDataChangedDelegate;

private:
	UPROPERTY(EditDefaultsOnly, Category="CreativeProxyManagerComponent")
	TSubclassOf<ACreativePlayerReplicationProxy> ProxyClass;

	UPROPERTY(Transient)
	TMap<FUniqueNetIdRepl, TObjectPtr<ACreativePlayerReplicationProxy>> ProxiesMap;

};

