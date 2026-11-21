// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortBrushSize.h"
#include "FortHeroLoadoutPerkTileBase.generated.h"

class UCommonTextBlock;
class UFortAbilityKit;
class UFortLazyImage;
class UHorizontalBox;
class URichTextBlock;
enum class EFortHeroPerkDisplayType : uint8;

UENUM(BlueprintType)
enum class EFortHeroPerkDisplayType : uint8
{
	CommanderPerk = 0,
	TeamPerk = 1,
	ClassPerk = 2,
	StandardPerk = 3,
	Max_None = 4 UMETA(Hidden),
};

USTRUCT(BlueprintType)
struct FFortInGamePerkDisplayData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortInGamePerkDisplayData")
	EFortHeroPerkDisplayType PerkDisplayType;

	UPROPERTY(EditAnywhere, Category="FortInGamePerkDisplayData")
	int32 Index;

	UPROPERTY(EditAnywhere, Category="FortInGamePerkDisplayData")
	int32 Row;

	UPROPERTY(EditAnywhere, Category="FortInGamePerkDisplayData")
	int32 Column;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortHeroLoadoutPerkTileBase : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnPerkInitialized(EFortHeroPerkDisplayType InPerkType, bool bActive, bool bShowWarning);

	UPROPERTY(EditAnywhere, Category="FortHeroLoadoutPerkTileBase")
	TEnumAsByte<EFortBrushSize::Type> BrushSize;

	UPROPERTY(EditAnywhere, Category="FortHeroLoadoutPerkTileBase")
	bool bShowSummaryDescription;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortHeroLoadoutPerkTileBase", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PerkName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<URichTextBlock> Text_Description;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> Image_PerkIcon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> Hbox_PerkDetails;

	UPROPERTY(EditAnywhere, Category="FortHeroLoadoutPerkTileBase")
	FText ActiveText;

	UPROPERTY(EditAnywhere, Category="FortHeroLoadoutPerkTileBase")
	FText InactiveText;

	UPROPERTY(EditAnywhere, Category="FortHeroLoadoutPerkTileBase")
	float InactiveOpacity;

	UPROPERTY(EditAnywhere, Category="FortHeroLoadoutPerkTileBase")
	float ActiveOpacity;

	UPROPERTY(Transient)
	TObjectPtr<UFortAbilityKit> AbilityKit;

};

