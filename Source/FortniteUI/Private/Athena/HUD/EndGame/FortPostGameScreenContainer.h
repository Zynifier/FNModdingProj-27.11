// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "FortPostGameScreenContainer.generated.h"

class UFortPostGameScreen;

UCLASS(meta=(DisableNativeTick))
class UFortPostGameScreenContainer : public UWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Preview")
	int32 ScreenPreviewIndex;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortPostGameScreen>> AllScreens;

};

