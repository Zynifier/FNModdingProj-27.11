// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SidecarDss.generated.h"

USTRUCT()
struct FSidecarFileInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TMap<FString, FString> Meta;

	UPROPERTY()
	bool bIsCheckedOut;

	UPROPERTY()
	bool bOperationPending;

	UPROPERTY()
	FString CheckoutGuid;

};

UCLASS(Config=Engine)
class SIDECARSYS_API USidecarDss : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TMap<FString, FSidecarFileInfo> FileInfoMap;

	UPROPERTY(Config)
	FString DssDownloadUrl;

	UPROPERTY(Config)
	FString DssCheckoutUrl;

	UPROPERTY(Config)
	FString DssUploadUrl;

	UPROPERTY(Config)
	FString DssRestoreUrl;

	UPROPERTY(Config)
	FString DssCheckinUrl;

	UPROPERTY(Config)
	FString DssListFilesUrl;

};

