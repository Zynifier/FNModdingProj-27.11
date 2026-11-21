// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortOpenCardPackModal.generated.h"

class UCommonButtonLegacy;
class UCommonListView;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRequestOpenCardPackDelegate, int32, PackIndex);

UCLASS(BlueprintType, meta=(DisableNativeTick))
class UFortOpenCardPackModal : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortOpenCardPackModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonListView> CardPackList;

protected:
	UPROPERTY(BlueprintReadWrite, Export, Category="FortOpenCardPackModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> OpenAllButton;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> CancelButton;

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FRequestOpenCardPackDelegate BPOnRequestOpenCardPack;

};

