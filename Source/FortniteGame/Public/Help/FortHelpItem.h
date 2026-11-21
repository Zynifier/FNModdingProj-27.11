// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Styling/SlateBrush.h"
#include "FortHelpItem.generated.h"

class UFortHelpItem;
class UUserWidget;

UENUM(BlueprintType)
enum class EFortHelpContentLocation : uint8
{
	Top = 0,
	Bottom = 1,
	Max = 2 UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EFortHelpItemType : uint8
{
	Header = 0,
	Entry = 1,
	Max = 2 UMETA(Hidden),
};

USTRUCT(BlueprintType)
struct FFortHelpAdditionalContent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHelpAdditionalContent")
	EFortHelpContentLocation ContentLocation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHelpAdditionalContent")
	bool ShowAdditionalImage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHelpAdditionalContent", meta=(EditCondition="ShowAdditionalImage"))
	FSlateBrush ImageToDisplay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHelpAdditionalContent")
	bool ShowAdditionalWidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHelpAdditionalContent", meta=(EditCondition="ShowAdditionalWidget"))
	TSubclassOf<UUserWidget> WidgetToDisplay;

};

UCLASS(Abstract, EditInlineNew, MinimalAPI, BlueprintType)
class UFortHelpItem : public UDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Help")
	virtual UFortHelpItem* GetItemWithID(const FName _ItemID);

	UFUNCTION(BlueprintCallable, Category="Help")
	virtual TArray<UFortHelpItem*> GetSubItems();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Help")
	EFortHelpItemType ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Help", meta=(MultiLine="TRUE"))
	FName ItemID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Help", meta=(MultiLine="TRUE"))
	FText HeaderName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Help", meta=(MultiLine="TRUE"))
	FText BodyText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Help")
	FFortHelpAdditionalContent AdditionalContent;

};

UCLASS(BlueprintType)
class UFortHelpItemCategory : public UFortHelpItem
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Entries")
	TArray<TObjectPtr<UFortHelpItem>> AssetSubItems;

	UPROPERTY(EditAnywhere, Instanced, Category="Entries")
	TArray<TObjectPtr<UFortHelpItem>> InlineSubItems;

};

UCLASS(BlueprintType)
class UFortHelpItemEntry : public UFortHelpItem
{
	GENERATED_BODY()

};

