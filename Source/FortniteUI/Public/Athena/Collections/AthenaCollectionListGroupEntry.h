// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserListEntry.h"
#include "CommonUserWidget.h"
#include "AthenaCollectionListGroupEntry.generated.h"

class UDynamicEntryBox;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaCollectionListGroupEntry : public UCommonUserWidget, public IUserListEntry
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true", EntryClass="AthenaCollectionListEntry"))
	TObjectPtr<UDynamicEntryBox> EntryBox_ListEntries;

};

