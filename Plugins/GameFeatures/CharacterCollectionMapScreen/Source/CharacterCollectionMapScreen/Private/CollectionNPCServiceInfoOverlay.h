// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Collections/AthenaCollectionScreenInfoOverlay.h"
#include "CollectionNPCServiceInfoOverlay.generated.h"

class UCollectionNPCServiceContainer;
class UCollectionScreenServiceVisualData;
class UImage;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UCollectionNPCServiceInfoOverlay : public UAthenaCollectionScreenInfoOverlay
{
	GENERATED_BODY()

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCollectionNPCServiceContainer> Services;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_ServiceIcon;

private:
	UPROPERTY(Transient)
	TObjectPtr<UCollectionScreenServiceVisualData> SharedServiceVisualData;

};

