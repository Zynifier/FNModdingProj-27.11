// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "AthenaSpectateMatchModalBase.generated.h"

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaSpectateMatchModalBase : public UFortActivatablePanel
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void BuildFriendNameIdMap();

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="Friend Names"))
	void GetFriendNames(TArray<FString>& FriendNames) const;

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="IsGameSessionString"))
	bool IsGameSessionString(const FString& String) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void JoinFriendSession(const FString& FriendName) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void JoinGameSession(const FString& GameSessionIdStr) const;

};

