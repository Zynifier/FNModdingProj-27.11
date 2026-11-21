// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Math/Color.h"
#include "AthenaSquadDisplayData.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FAthenaTeamDisplayInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaTeamDisplayInfo", meta=(AllowedClasses="/Script/Engine.MaterialInterface,/Script/Engine.Texture2D"))
	TSoftObjectPtr<UObject> Icon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaTeamDisplayInfo", meta=(AllowedClasses="/Script/Engine.MaterialInterface,/Script/Engine.Texture2D"))
	TSoftObjectPtr<UObject> Ribbon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaTeamDisplayInfo")
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaTeamDisplayInfo")
	FLinearColor TextColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaTeamDisplayInfo")
	FLinearColor PedestalColor;

};

UCLASS()
class UAthenaTeamDisplayData : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="AthenaTeamDisplayData")
	TArray<FAthenaTeamDisplayInfo> SquadStyles;

	UPROPERTY(EditAnywhere, Category="AthenaTeamDisplayData")
	FAthenaTeamDisplayInfo DefaultStyle;

};

