// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LocalPlayer.h"
#include "ValkyrieLocalPlayer.generated.h"

class UFortClientSettingsRecord;
class UValkyrieOnlineAccount;
class UValkyrieOnlineInstance;

UCLASS()
class VALKYRIEACCOUNT_API UValkyrieLocalPlayer : public ULocalPlayer
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<UValkyrieOnlineInstance> OnlineInstance;

	UPROPERTY(Transient)
	TObjectPtr<UValkyrieOnlineAccount> OnlineAccount;

	UPROPERTY(Transient)
	TObjectPtr<UFortClientSettingsRecord> ClientSettingsRecord;

};

