// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CollectionNPCServiceGroup.generated.h"

class UDynamicEntryBox;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UCollectionNPCServiceGroup : public UUserWidget
{
	GENERATED_BODY()

public:
	UCollectionNPCServiceGroup(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true", EntryClass="CollectionNPCServiceWidget"))
	UDynamicEntryBox* EntryBox_Services;

};

