// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "FortHotfixToolAssetEntry.generated.h"

class UComboBoxString;
class UObject;

UCLASS()
class UFortHotfixToolAssetEntry : public UEditorUtilityWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void InitHotfixAssetEntry(UObject* Asset);

	UFUNCTION(BlueprintImplementableEvent)
	void OnHotfixChangeFound(const FString& RowName, const FString& ColumnName, const FString& OldValue, const FString& NewValue);

	UFUNCTION(BlueprintCallable)
	void UpdateHotfixTypeForAsset(const UObject* Asset, const FString& HotfixType);

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortHotfixToolAssetEntry", meta=(BindWidget, EditInline="true"))
	UComboBoxString* ComboBox_HotfixType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortHotfixToolAssetEntry")
	TArray<FString> AssetHotfixes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortHotfixToolAssetEntry")
	FString AssetHotfixComment;

};

