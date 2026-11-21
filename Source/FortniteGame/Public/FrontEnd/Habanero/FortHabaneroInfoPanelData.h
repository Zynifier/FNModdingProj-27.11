// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortHabaneroInfoPanelData.generated.h"

class UTexture2D;
class UUserWidget;

UCLASS(BlueprintType)
class UFortHabaneroInfoPanelData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Info Details", meta=(DisplayName="Details List"))
	TArray<FText> BulletList;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Info Details", meta=(DisplayName="Title"))
	FText Title;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Info Details", meta=(AllowPrivateAccess, DisplayName="Image"))
	TObjectPtr<UTexture2D> Image;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Info Details", meta=(AllowPrivateAccess, DisplayName="Panel Type"))
	TSubclassOf<UUserWidget> PanelType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Info Details", meta=(AllowPrivateAccess, DisplayName="Details List 2"))
	TArray<FText> BulletList2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Info Details", meta=(AllowPrivateAccess, DisplayName="Image on Left"))
	bool ImageOnLeft;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Info Details", meta=(AllowPrivateAccess, DisplayName="ButtonName"))
	FText ButtonName;

};

