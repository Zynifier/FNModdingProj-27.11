// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/FortCheatManager.h"
#include "PictureInPictureCheatManager.generated.h"

UCLASS()
class UPictureInPictureCheatManager : public UChildCheatManager
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Exec)
	void CanEnablePartnerPiP();

	UFUNCTION(BlueprintCallable, Exec)
	void DisablePiP();

	UFUNCTION(BlueprintCallable, Exec)
	void EnablePiP();

	UFUNCTION(BlueprintCallable, Exec)
	void PrintPiPRegionInfo();

	UFUNCTION(BlueprintCallable, Exec)
	void ResumePiP();

	UFUNCTION(BlueprintCallable, Exec)
	void SuspendPiP();

};

