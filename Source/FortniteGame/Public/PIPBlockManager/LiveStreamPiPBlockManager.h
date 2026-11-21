// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LiveStreamPiPBlockManager.generated.h"

class ULiveStreamPiPBlockManager;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPIPPlayerBlockedChanged, bool, PIPIsBlocking);

UCLASS(MinimalAPI, HideCategories=("Object"))
class ULiveStreamPiPBlockManager : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	static ULiveStreamPiPBlockManager* GetPiPBlockManager();

	UFUNCTION(BlueprintPure)
	bool IsOutSideBlocked() const;

	UFUNCTION(BlueprintPure)
	bool IsPlayerBlocked() const;

	UFUNCTION(BlueprintCallable)
	void SetPlayerBlocked(bool bInBlocked, bool bInOutsideBlocked = false);

	UPROPERTY(BlueprintAssignable)
	FPIPPlayerBlockedChanged PIPPlayerBlockingEvent;

};

