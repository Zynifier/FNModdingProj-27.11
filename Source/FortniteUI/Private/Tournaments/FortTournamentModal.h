// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortTournamentModal.generated.h"

class UFortTournamentDetailsPage;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortTournamentModal : public UFortActivatablePanel
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnTournamentSet(FLinearColor LeftColor, FLinearColor RightColor);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortTournamentDetailsPage> TournamentDetailsPage;

};

