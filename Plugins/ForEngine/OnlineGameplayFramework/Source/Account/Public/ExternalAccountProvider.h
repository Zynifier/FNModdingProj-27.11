// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ExternalAccountProvider.generated.h"

UENUM(BlueprintType, meta=(IsBlueprintBase="true"))
enum class EExternalAccountType : uint8
{
	None = 0,
	/** Facebook account login */
	Facebook = 1,
	/** Google account login */
	Google = 2,
	/** Epic account portal login for PSN */
	Epic_PSN = 3,
	/** Epic account portal login for XBL */
	Epic_XBL = 4,
	/** Epic account portal login for Erebus */
	Epic_Erebus = 5,
	/** Epic account portal login for Facebook */
	Epic_Facebook = 6,
	/** Epic account portal login for Google */
	Epic_Google = 7,
	/** Epic account portal with all available login methods */
	Epic_Portal = 8,
};

USTRUCT()
struct FExternalAccountServiceConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	EExternalAccountType Type;

	UPROPERTY(Config)
	FName ExternalServiceName;

};

UCLASS(Config=Engine)
class ACCOUNT_API UExternalAccountProvider : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Config)
	TArray<FExternalAccountServiceConfig> Services;

};

