// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "STW/Items/FortAlterableItem.h"
#include "FortAlterationOptionsBase.generated.h"

class UCommonButtonGroupLegacy;
class UCommonButtonLegacy;
class UFortAlterableItem;
class UFortAlterationOption;
enum class EFortAlterationOptionType : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortAlterationOptionsBase : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="FortAlterationOptionsBase")
	bool DoAlterationOptionsExist(EFortAlterationOptionType OptionType) const;

	UFUNCTION()
	void HandleAlterationsOptionHovered(UCommonButtonLegacy* AlterationOptionButton, int32 GroupIndex);

	UFUNCTION()
	void HandleAlterationsOptionSelected(UCommonButtonLegacy* AlterationOptionButton, int32 GroupIndex);

	UFUNCTION(BlueprintPure, Category="FortAlterationOptionsBase")
	bool IsValidAlterationSlot() const;

	UFUNCTION(BlueprintImplementableEvent, Category="FortAlterationOptionsBase")
	void OnGenerateOption(EFortAlterationOptionType OptionType, UFortAlterationOption* OptionWidget);

	UFUNCTION(BlueprintImplementableEvent, Category="FortAlterationOptionsBase")
	void OnItemChanged(bool bIntroAlterations);

	UFUNCTION(BlueprintCallable, Category="FortAlterationOptionsBase")
	void ProcessAlterationOptions(bool bIntroAlterations = false);

protected:
	UPROPERTY(EditAnywhere, Category="FortAlterationOptionsBase")
	TSubclassOf<UFortAlterationOption> AlterationOptionClass;

	UPROPERTY(BlueprintReadOnly, Category="FortAlterationOptionsBase")
	TObjectPtr<UCommonButtonGroupLegacy> AlterationOptionButtons;

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortAlterableItem> Item;

	UPROPERTY(Transient)
	int32 SlotIndex;

	UPROPERTY(Transient)
	bool bUpgradeOptionExists;

	UPROPERTY(Transient)
	FAlterationOption UpgradeOption;

	UPROPERTY(Transient)
	TArray<FAlterationOption> RespecOptions;

};

