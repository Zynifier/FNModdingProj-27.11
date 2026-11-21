// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Types/SlateEnums.h"
#include "Cosmetics/Variants/FortMcpVariantChannelInfo.h"
#include "Variants/FortVariantEditorWidgetBase.h"
#include "FortVariantRedirectorTile.generated.h"

class UAthenaCosmeticItemDefinition;
class UCommonTextBlock;
class UDynamicEntryBox;
class UFortItemDefinition;
class UFortVariantSprayCustomizer;
class UFortVariantSprayCustomizerConfig;
class UWidget;

USTRUCT()
struct FFortVariantRedirectorTileLoadedEmoteToRandomize
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<UFortItemDefinition> LoadedEmote;

};

UCLASS(Abstract, meta=(Category="MeshCosmetics UI", DisableNativeTick))
class UFortVariantRedirectorTile : public UFortVariantEditorWidgetBase
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnVariantChangedEvent, const FMcpVariantChannelInfo&, InChannelInfo);

protected:
	UFUNCTION(BlueprintPure)
	virtual UWidget* GetButtonToFocus() const;

private:
	UFUNCTION()
	UWidget* HandleBoundaryNavigation(EUINavigation InNavigation);

	UPROPERTY(Export, meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> EntryBox_VariantOptions;

	UPROPERTY(Export, meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_VariantName;

	UPROPERTY(EditDefaultsOnly, Category="FortVariantRedirectorTile")
	TSoftClassPtr<UFortVariantSprayCustomizer> SprayCustomizerClass;

	UPROPERTY(EditDefaultsOnly, Category="FortVariantRedirectorTile")
	TObjectPtr<UFortVariantSprayCustomizerConfig> SprayCustomizerConfig;

	UPROPERTY(EditDefaultsOnly, Category="FortVariantRedirectorTile", meta=(RowType="/Script/CommonUI.CommonInputActionDataBase"))
	FDataTableRowHandle ClearAllSlotsInputAction;

	UPROPERTY(EditDefaultsOnly, Category="FortVariantRedirectorTile", meta=(RowType="/Script/CommonUI.CommonInputActionDataBase"))
	FDataTableRowHandle RandomizeSpraysInputAction;

	UPROPERTY()
	TWeakObjectPtr<UAthenaCosmeticItemDefinition> ItemDefinition;

	UPROPERTY(Transient)
	TArray<FFortVariantRedirectorTileLoadedEmoteToRandomize> LoadedEmotesToRandomize;

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FOnVariantChangedEvent OnVariantEngagedEvent;

};

