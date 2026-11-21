// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonButtonBase.h"
#include "FortCreativePropertyEditorEventBindingDialogListEntry.generated.h"

class UCommonTextBlock;

UCLASS(Abstract, Blueprintable, meta=(DisableNativeTick, NotBlueprintType="true"))
class UFortCreativePropertyEditorEventBindingDialogListEntry : public UCommonButtonBase, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnDisplayNameSet(const FText& DisplayName);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativePropertyEditorEventBindingDialogListEntry", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_EntryName;

};

