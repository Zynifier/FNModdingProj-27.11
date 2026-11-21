// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/FortCheatManager.h"
#include "PictureInPictureFNEventsCheatManager.generated.h"

UCLASS()
class UPictureInPictureFNEventsCheatManager : public UChildCheatManager
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Exec)
	void AddPiPEvent(const FString& EventName, const FString& VUID);

	UFUNCTION(BlueprintCallable, Exec)
	void ListAllPiPEvents();

	UFUNCTION(BlueprintCallable, Exec)
	void ListPiPEvents();

	UFUNCTION(BlueprintCallable, Exec)
	void RemovePiPEvent(const FString& EventName);

	UFUNCTION(BlueprintCallable, Exec)
	void SelectPiPEvent(const FString& EventName);

	UFUNCTION(BlueprintCallable, Exec)
	void StartPiPBouncingLlama();

	UFUNCTION(BlueprintCallable, Exec)
	void StopPiPBouncingLlama();

};

