// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Athena/AI/Systems/AthenaAIServicePlayerBots.h"
#include "AthenaAIServiceCreativePlayerBots.generated.h"

class AActor;
class AFortMinigame;
class APlayerController;
enum class EFortMinigameState : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMinigameBotsReady);

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UAthenaAIServiceCreativePlayerBots : public UAthenaAIServicePlayerBots
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	FORTNITEAI_API void AddHiringHistory(AActor* HiredOwner, APlayerController* HiringPlayer);

	UFUNCTION(BlueprintCallable)
	FORTNITEAI_API void ClearHiringHistory(AActor* HiredOwner);

	UFUNCTION(BlueprintPure)
	FORTNITEAI_API const APlayerController* GetLastHiringPlayer(const AActor* HiredOwner) const;

	UFUNCTION(BlueprintPure)
	FORTNITEAI_API virtual bool IsMinigameBotSpawningRequired() const;

	UFUNCTION()
	FORTNITEAI_API virtual void OnMinigameStateChanged(AFortMinigame* Minigame, EFortMinigameState MinigameState);

	UPROPERTY(BlueprintAssignable)
	FOnMinigameBotsReady OnMinigameBotsReady;

protected:
	UFUNCTION()
	FORTNITEAI_API void OnFinishedAddingMinigamePlayer(FUniqueNetIdRepl UniqueNetId, bool bIsLocalPlayer);

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortMinigame> CachedMinigame;

private:
	UPROPERTY(Transient)
	TMap<TObjectPtr<AActor>, TObjectPtr<APlayerController>> HiringHistory;

};

