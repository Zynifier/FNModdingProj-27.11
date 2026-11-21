// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UObject/NoExportTypes.h"
#include "FortDottedPagination.generated.h"

class UListView;

UCLASS(Abstract)
class UFortDottedPagination : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortDottedPagination(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY(EditDefaultsOnly, Category="Pagination Settings")
	bool bUseWrapping;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UListView> ListView_Dots;

};

UCLASS()
class UFortPageDotItem : public UObject
{
	GENERATED_BODY()

};

