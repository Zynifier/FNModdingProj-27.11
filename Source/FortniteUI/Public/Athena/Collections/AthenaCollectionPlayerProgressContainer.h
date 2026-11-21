// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaCollectionPlayerProgressContainer.generated.h"

class UAthenaCollectionPlayerProgress;

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UAthenaCollectionPlayerProgressContainer : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Player Progress Container Reset"))
	void BP_OnPlayerProgressContainerReset();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Player Progress Entries Created"))
	void BP_OnPlayerProgressEntriesCreated(const TArray<UAthenaCollectionPlayerProgress*>& PlayerProgressEntries, int32 NumToCollect);

private:
	UPROPERTY(EditAnywhere, Category="AthenaCollectionPlayerProgressContainer")
	TSubclassOf<UAthenaCollectionPlayerProgress> PlayerProgressClass;

	UPROPERTY(EditAnywhere, Category="AthenaCollectionPlayerProgressContainer", meta=(ClampMin="0.000000"))
	float CycleDelay;

	UPROPERTY(EditAnywhere, Category="AthenaCollectionPlayerProgressContainer", meta=(ClampMin="0"))
	int32 ShowLocalPlayerAfterNumEntries;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UAthenaCollectionPlayerProgress>> CachedPlayerProgressEntries;

};

