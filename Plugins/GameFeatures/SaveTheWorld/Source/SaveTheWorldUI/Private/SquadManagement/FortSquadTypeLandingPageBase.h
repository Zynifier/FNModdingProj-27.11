// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CommonButtonLegacy.h"
#include "FortInventoryFilterEnum.h"
#include "STW/FortHomebase/FortHomebaseManager.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortSquadTypeLandingPageBase.generated.h"

class UFortSquadSelectorButton;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortSquadSelectorButton : public UCommonButtonLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Squad Management")
	FName GetIdOfSquadToManageBP() const;

	UFUNCTION(BlueprintCallable, Category="Squad Management")
	void SetIdOfSquadToManageBP(const FName& SquadId);

	UFUNCTION(BlueprintPure, Category="Squad Management")
	bool TryGetStaticSquadDataBP(FHomebaseSquad& OutSquadData) const;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Squad Management")
	void HandleDifferentSquadSetBP();

	UFUNCTION(BlueprintImplementableEvent, Category="Squad Management")
	void HandleSquadChangedBP();

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortSquadTypeLandingPageBase : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Squad Type Landing Page")
	bool IsScreenWIFE() const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Squad Type Landing Page")
	void ShowWarningReadOnlyWIFE(bool Force);

	UPROPERTY(BlueprintReadWrite, Category="Squad Type Landing Page|Mode")
	bool bReadOnlyModeWIFE;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Squad Type Landing Page")
	UFortSquadSelectorButton* CreateAndAddSquadButton(const FName& SquadId);

	UFUNCTION(BlueprintCallable, Category="Squad Type Landing Page")
	void HandleBackInputAction(bool& bPassThrough);

	UFUNCTION(BlueprintCallable, Category="Squad Type Landing Page")
	void HandlePendingNavigationOp();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Squad Type Landing Page")
	EFortHomebaseSquadType SquadType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Squad Type Landing Page", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle BackInputActionRowHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Squad Type Landing Page")
	EFortFrontendInventoryFilter ItemManagementScreenFilter;

	UPROPERTY(Export)
	TArray<TWeakObjectPtr<UFortSquadSelectorButton>> SquadSelectorButtons;

};

