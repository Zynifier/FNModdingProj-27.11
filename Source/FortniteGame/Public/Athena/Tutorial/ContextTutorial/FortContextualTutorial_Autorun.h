// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Tutorial/ContextTutorial/FortContextualTutorial.h"
#include "FortMovementEnums.h"
#include "FortContextualTutorial_Autorun.generated.h"

UCLASS()
class UFortContextualTutorial_Autorun : public UFortContextualTutorial
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void BindMovementStyleChanged();

	UFUNCTION()
	void HandleOnAutoRunChanged(bool bIsEnabled);

	UFUNCTION()
	void HandleOnMovementStyleChanged(EFortMovementStyle::Type PreviousMovementStyle, EFortMovementStyle::Type CurrentMovementStyle);

};

